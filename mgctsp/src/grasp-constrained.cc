/*
 * File name: mkgreed.cc
 * Date:      2016/12/07 08:32
 * Author:    Jan Faigl
 */

#include <limits>

#include <boost/foreach.hpp>

#include <crl/random.h>
#include <crl/logging.h>
#include <crl/assert.h>
#include <crl/file_utils.h>

#include <crl/gui/shape.h>
#include <crl/gui/shapes.h>

#include "grasp-constained.h"

#include "insertion.h"
#include "target.h"

#include "canvasview_coords.h"
#include "canvasview_mkgreed.h"

#define foreach BOOST_FOREACH

using namespace graspc;

typedef std::vector<int> IntVector;

using namespace crl;
using namespace crl::gui;

/// - static method ------------------------------------------------------------
crl::CConfig& CMKGREED::getConfig(crl::CConfig &config) 
{
  // basic properties not included in the crl_algorithm
  Base::getConfig(config);
  config.add<bool>("save-info", "disable/enable save info", true);
  config.add<bool>("save-settings", "disable/enable save settings", true);

  config.add<std::string>("result-path", "file name for the final found path (ring) as sequence of points",
      "path");
  config.add<std::string>("pic-dir", "relative directory in result directory to store pictures from each iteration");
  config.add<std::string>("pic-ext",
      "extension of pic, eps, png, pdf, svg (supported by particular gui renderer rendered",
      "png");
  config.add<bool>("save-pic", "enable/disable saving pictures (after each refine)");
  // 
  //
  // Problem specification
  config.add<std::string>("problem", "Problem file");
  config.add<std::string>("method", "Specify method in the result log", "mkgreed");
  //
  // Gui properties
  config.add<std::string>("draw-shape-targets", "Shape of the target", Shape::CITY());
  config.add<std::string>("draw-shape-neurons", "Shape of the neurons", Shape::NEURON());
  config.add<std::string>("draw-shape-path", "Shape of the path", Shape::RED_LINE());
  config.add<std::string>("draw-shape-ring", "Shape of the ring", Shape::GREEN_BOLD_LINE());
  config.add<std::string>("draw-shape-path-nodes", "Shape of the path nodes", Shape::MAP_VERTEX());
  config.add<bool>("draw-ring-iter", "enable/disable drawing ring at each iteration", false);
  config.add<bool>("draw-ring", "Enable/Disable drawing ring in the final shoot", true);
  config.add<bool>("draw-path", "Enable/Disable drawing ring in the final shoot", true);
  config.add<bool>("draw-path-nodes", "enable/disable drawing path vertices(nodes)", true);

  config.add<double>("max-cost", "Max cost of one route", 200);
  config.add<double>("pylon-cost", "Cost of pylon visit", 10);
  config.add<double>("distance", "Distane from center to search", 500);
  config.add<int>("m-init", "Initial number of agents", 3);

  config.add<int>("p1", "Weight p1", 1);
  config.add<int>("p2", "Weight p2", 2);
  config.add<int>("p3", "Weight p3", 3);
  config.add<int>("R-t", "Number of iterations to reset scores", 20);
  config.add<int>("size-neigborhood", "Size of solution neighborhood", 50);
  config.add<int>("size-tabu-list", "Tabu list size", 50);
  config.add<int>("tabu-iterations", "Maximum number of tabu search iterations", 100);
  config.add<int>("tabu-period", "After how many nodes to do TabuSerach", 20);
  config.add<int>("size-rcl", "Size of resctricted candidate list", 5);

  return config;
}

/// - constructor --------------------------------------------------------------
CMKGREED::CMKGREED(crl::CConfig &config) : Base(config, "TRIAL"),
  SAVE_RESULTS(config.get<bool>("save-results")),
  SAVE_SETTINGS(config.get<bool>("save-settings")),
  SAVE_INFO(config.get<bool>("save-info")),
  DRAW_RING_ITER(config.get<bool>("draw-ring-iter")),
  DRAW_RING_ENABLE(config.get<bool>("draw-ring")),
  SAVE_PIC(config.get<bool>("save-pic")),
  maxCost(config.get<double>("max-cost")),
  pylonCost(config.get<double>("pylon-cost")),
  dist(std::pow(config.get<double>("distance"),2)),
  m(config.get<int>("m-init")),
  p1(config.get<int>("p1")),
  p2(config.get<int>("p2")),
  p3(config.get<int>("p3")),
  R_T(config.get<int>("R-t")),
  sizeNeighborhood(config.get<int>("size-neigborhood")),
  sizeTabuList(config.get<int>("size-tabu-list")),
  tabuIterations(config.get<int>("tabu-iterations")),
  tabuPeriod(config.get<int>("tabu-period")),
  sizeRCL(config.get<int>("size-rcl"))
{
  shapeTargets.setShape(config.get<std::string>("draw-shape-targets"));
  shapePath.setShape(config.get<std::string>("draw-shape-path"));
  shapePathNodes.setShape(config.get<std::string>("draw-shape-path-nodes"));
  method = config.get<std::string>("method");



  const std::string fname = config.get<std::string>("problem");
  { // load problem
    targets.push_back(new STarget(targets.size(), Coords(0,0),true)); // initial point
    std::ifstream in(fname);
    Coords pt;
    while (in >> pt) {
      if(pt.squared_distance(targets.at(0)->coords) <= this->dist)
        targets.push_back(new STarget(targets.size(), pt));
    }
  }


  if (name.size() == 0) {
    std::string n = getBasename(fname);
    size_t i = n.rfind(".txt");
    if (i != std::string::npos) {
      name = n.erase(i, 4);
    }
  }

}

/// - destructor ---------------------------------------------------------------
CMKGREED::~CMKGREED()
{
  foreach(STarget *target, targets) {
    delete target;
  }
}

/// - public method ------------------------------------------------------------
std::string CMKGREED::getVersion(void) 
{
  return "GSOA ETSP 1.0";
}

/// - public method ------------------------------------------------------------
std::string CMKGREED::getRevision(void) 
{
  return "$Id: mkgreed.cc 234 2018-08-16 20:09:49Z jf $";
}

/// - public method ------------------------------------------------------------
void CMKGREED::solve(void) 
{
  crl::CRandom::randomize();
  Base::solve();
}

/// - protected method ---------------------------------------------------------
void CMKGREED::load(void)
{
  CoordsVector coords;
  foreach(STarget* target, targets){
    coords.push_back(target->coords);
  }


  if (canvas) {
    *canvas 
      << canvas::AREA << coords << canvas::END
      << "targets" << shapeTargets << canvas::POINT 
      << coords
      << canvas::REDRAW
      ;
  }
  DEBUG("MKGREED::load -- done");
}

/// - protected method ---------------------------------------------------------
void CMKGREED::initialize(void)
{
  /*permutation.clear();
    foreach(const STarget *target, targets) {
    permutation.push_back(target->label);
    }*/
}

/// - protected method ---------------------------------------------------------
void CMKGREED::after_init(void) 
{
  //  tLoad.append(loadTimer);
  //  tInit.append(initTimer);
}

/// - protected method ---------------------------------------------------------
void CMKGREED::iterate(int iter) 
{

  bool validSolution = false;


  crl::CRandom::randomize();
  finalSolution.clear();

  if (canvas) {
    *canvas << canvas::CLEAR << "path" << "path";
  }

  R_T_iterator = 0;
  g1Score = 1;
  g2Score = 1;
  g3Score = 1;

  int step = 1;

  double bestSolutionLength = std::numeric_limits<double>::max();
  bool term = false;

  double cost;
  int bestAgent;
  int bestTarget;
  int bestInsertIndex;
  CoordsVector costCoords;
  Coords currentCoords;

  int random;

  std::set<Insertion*, InsComp> possibleInsertions;
  Insertion* chosenInsertion;

  std::string debug;

  CoordsVectorVector currentSolution;
  for(int i = 0; i < m; i++){
    CoordsVector coordsVec;
    coordsVec.push_back(targets.at(0)->coords);
    currentSolution.push_back(coordsVec);
  }

  // initial search in close neighborhood

  while ((step < targets.size()) && not term) {

    DEBUG("Greedy Random search step: " << step);
    for(int i = 1; i < targets.size(); i++){
      if(targets.at(i)->visited == false){
        currentCoords = targets.at(i)->coords;
        for(int j = 0; j < m; j++){   
          for(int k = 1; k <= currentSolution.at(j).size(); k++){
            costCoords = currentSolution.at(j);
            costCoords.insert(costCoords.begin()+k,currentCoords);
            cost = get_path_cost(costCoords); 
            possibleInsertions.insert(new Insertion(cost, i, j, k));
          }
        }
      }
    }  

    sizeRCL = std::floor((double)possibleInsertions.size() / 4.);

    random = std::rand() % sizeRCL;
    while(random >= possibleInsertions.size()){ random--;}
    chosenInsertion = *std::next(possibleInsertions.begin(), random);
    bestTarget = chosenInsertion->Target;
    bestAgent = chosenInsertion->Agent;
    bestInsertIndex = chosenInsertion->InsertIndex;

    for (std::set<Insertion*>::iterator ins = possibleInsertions.begin(); ins != possibleInsertions.end(); ++ins) {
      delete *ins;
    }
    possibleInsertions.clear();

    targets.at(bestTarget)->visited = true;
    currentSolution.at(bestAgent).insert(currentSolution.at(bestAgent).begin()+bestInsertIndex,targets.at(bestTarget)->coords);

    //      std::cout << "Inserted "<< currentSolution.at(bestAgent).back() << " to agent " << bestAgent <<std::endl;
    //      if(step >= tabuPeriod && step % tabuPeriod == 0)
    //      {
    //         currentSolution = getTSSolution(currentSolution, step);
    //      }
    step++;
  }


  while(!validSolution){
    currentSolution = getTSSolution(currentSolution, step);
    DEBUG("Final cost: "<<get_solution_cost(currentSolution);
    validSolution = true;

    for(auto somepath : currentSolution){
      if(validSolution && get_path_cost(somepath) > maxCost){
        validSolution = false;
        int averagePathSize = 0;
        for(auto somepath : currentSolution)
          averagePathSize = somepath.size();
        averagePathSize /= (currentSolution.size()+1);

        if (canvas) {
          *canvas << canvas::CLEAR << "path" << "path";
        }

        R_T_iterator = 0;
        g1Score = 1;
        g2Score = 1;
        g3Score = 1;

        CoordsVector coordsVec;
        coordsVec.push_back(targets.at(0)->coords);
        currentSolution.push_back(coordsVec);
        std::set<TargetShift,TargetShiftComp> possibleShifts;
        for (int i = 0; i < averagePathSize; i++) {
          for (int j = 0; j < m; j++) {
            for(int k = 1; k < currentSolution.at(j).size();k++){
                for (int l = 0; l < currentSolution.back().size(); l++){
                CoordsVector sourcePath = CoordsVector(currentSolution.at(j)); 
                CoordsVector targetPath = CoordsVector(currentSolution.back());
                targetPath.insert(targetPath.begin()+l+1, sourcePath.at(k));
                sourcePath.erase(sourcePath.begin()+k);
                double shiftCost = get_path_cost(sourcePath)+get_path_cost(targetPath);
                possibleShifts.insert(TargetShift(shiftCost,j,k,m,l+1));
                }
                }
                }
                int selectedShiftIndex = std::rand() % (int)std::floor((double)possibleShifts.size() / 4.);
                TargetShift sh = *std::next(possibleShifts.begin(),selectedShiftIndex);
                currentSolution.back().insert(currentSolution.back().begin()+sh.InsertIndex,currentSolution.at(sh.Agent1Index).at(sh.SourceIndex));
                currentSolution.at(sh.Agent1Index).erase(currentSolution.at(sh.Agent1Index).begin()+sh.SourceIndex);
                }
                m++;
                }
                }
                finalSolution = currentSolution;
                tSolve.stop();
                }
                }

/// - protected method ---------------------------------------------------------
void CMKGREED::save(void) 
{
  std::string dir;
  updateResultRecordTimes(); //update timers as load and initilization is outside class
  if (SAVE_SETTINGS) {
    saveSettings(getOutputIterPath(config.get<std::string>("settings"), dir));
  }
  if (SAVE_INFO) {
    saveInfo(getOutputIterPath(config.get<std::string>("info"), dir));
  }
  if (SAVE_RESULTS) {
    std::string file = getOutputIterPath(config.get<std::string>("result-path"), dir);
    assert_io(createDirectory(dir), "Cannot create file in the path'" + file + "'");

    const int i = 0;
    std::stringstream ss;
    ss << file << "-" << std::setw(2) << std::setfill('0') << i << ".txt";
    std::ofstream ofs(ss.str());
    assert_io(not ofs.fail(), "Cannot create path '" + ss.str() + "'");
    ofs << std::setprecision(14);
    for(int i = 0; i < m; i++){
      foreach(const Coords pt, finalSolution.at(i)) {
        ofs << pt.x << " " << pt.y << ", ";
      }
      ofs << std::endl;
    }

    assert_io(not ofs.fail(), "Error occur during path saving");
    ofs.close();
  }
  if (canvas) { // map must be set
    *canvas << canvas::CLEAR << "ring";
    if (config.get<bool>("draw-path")) {
      drawPath();
    } else if (DRAW_RING_ENABLE) {
      drawRing(-1);
    }
    saveCanvas();
  }
}

/// - protected method ---------------------------------------------------------
void CMKGREED::release(void) 
{
}

/// - protected method ---------------------------------------------------------
void CMKGREED::defineResultLog(void) 
{
  static bool resultLogInitialized = false;
  if (!resultLogInitialized) {
    resultLog << result::newcol << "NAME";
    resultLog << result::newcol << "METHOD";
    resultLog << result::newcol << "TRIAL";
    resultLog << result::newcol << "RTIME";
    resultLog << result::newcol << "CTIME";
    resultLog << result::newcol << "UTIME";
    resultLog << result::newcol << "LENGTH"; 
    resultLog << result::newcol << "STEPS";
    resultLog << result::newcol << "SOLUTION_STEP";
    resultLogInitialized = true;
  }
}

/// - protected method ---------------------------------------------------------
void CMKGREED::fillResultRecord(int trial) 
{
  resultLog << result::newrec << name << method << trial;
  long t[3] = {0l, 0l, 0l};
  tLoad.addTime(t);
  tInit.addTime(t);
  tSolve.addTime(t);
  tSave.addTime(t);
  resultLog << t[0] << t[1] << t[2];
}

/// - private method -----------------------------------------------------------
void CMKGREED::drawPath(void)
{
  CoordsVector path;
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < finalSolution.at(i).size(); j++)
    {
      //DEBUG("Drawing path "<<i<<" of size "<<finalSolution.at(i).size()+" "<<finalSolution.at(i).at(j).x<<" "<<finalSolution.at(i).at(j).y);
      path.push_back(finalSolution.at(i).at(j));
    }
  }

  if (canvas) {
    *canvas << canvas::CLEAR << "path" << "path"
      << CShape(config.get<std::string>("draw-shape-path"))
      << canvas::LINESTRING
      << path
      << path.front()
      << canvas::END;
  }

  DEBUG("MKGREED::drawing path -- done");

  /*if (config.get<bool>("draw-path-nodes")) {
   *canvas << canvas::POINT << shapePathNodes << finalSolution;
   } //end draw-path-nodes*/
  //end if canvas
}

/// - private method -----------------------------------------------------------
void CMKGREED::drawRing(int step)
{
  /*if (canvas) {
   *canvas << canvas::CLEAR << "ring" << "ring";
   if (DRAW_RING_ENABLE) {
   *canvas 
   << canvas::LINESTRING << shapeRing
   << ring << ring->begin()
   << canvas::END;
   } //end ring
   } //end canvas*/
}

/// - private method -----------------------------------------------------------
void CMKGREED::savePic(int step, bool detail, const std::string &dir_suffix)
{
  static int lastStep = step;
  static int i = 0;
  if (lastStep != step) {
    i = 0;
  }
  if (canvas) {
    canvas->redraw();
    std::string dir;
    std::string file = getOutputIterPath(config.get<std::string>("pic-dir") + dir_suffix, dir);
    assert_io(createDirectory(file), "Cannot create file in path '" + file + "'");
    std::stringstream ss;
    ss << file << "/" << "iter-" << std::setw(3) << std::setfill('0') << step;
    ss << "-" << std::setw(4) << std::setfill('0') << i;

    std::string suffixes(config.get<std::string>("pic-ext"));
    if (!suffixes.empty()) {
      std::string::size_type cur = 0;
      std::string::size_type next;
      do {
        next = suffixes.find(',', cur);
        const std::string &ext = suffixes.substr(cur, next - cur);
        if (!ext.empty()) {
          assert_io(canvas->save(ss.str() + "." + ext), "Cannot create output canvas file '" + file + "'");
        }
        cur = next + 1;
      } while (next != std::string::npos);
    } else {
      ss << "." << config.get<std::string>("pic-ext");
      assert_io(canvas->save(ss.str()), "Cannot create output canvas file '" + ss.str() + "'");
    }
  }
  lastStep = step;
  i++;
}

CoordsVectorVector CMKGREED::getTSSolution(CoordsVectorVector& prevSol, int nodes)
{
  int totalScore;
  int random;
  CoordsVectorVector tabuSolution;
  std::list<CoordsVectorVector> tabuList;
  double bestSolutionLength = get_solution_cost(prevSol);

  DEBUG("Initial tabu score is "<<bestSolutionLength<<" "<<prevSol.size()<<" "<<m);
  int tabuIterationsDynamic = 10*nodes;
  int bestGroup = 0;
  double bestNeighborhoodLength;
  double tabuSolutionLength;
  CoordsVectorVector bestNeigborhoodSolution = prevSol;
  tabuList.push_back(prevSol);

  for(int iteration = 0; iteration < tabuIterationsDynamic; iteration++)
  {

    bestNeighborhoodLength = std::numeric_limits<double>::max();

    // reinitialize score each R_t iterations
    if(++R_T_iterator >= R_T)
    {
      g1Score = 1;
      g2Score = 1;
      g3Score = 1;
      R_T_iterator = 0;
    }

    // search solution neigborhood
    for(int j = 0; j < nodes*m; j++)
    {
      tabuSolution = bestNeigborhoodSolution;
      totalScore = g1Score+g2Score+g3Score;
      random = (std::rand() % totalScore);
      if (random < g1Score){
        getG1Solution(tabuSolution);
      }else if (random < (g1Score+g2Score)){
        getG2Solution(tabuSolution);
      }else{
        getG3Solution(tabuSolution);
      }
      tabuSolutionLength = get_solution_cost(tabuSolution);
      if(tabuSolutionLength < bestNeighborhoodLength && std::find(tabuList.begin(),tabuList.end(),tabuSolution) == tabuList.end())
      {
        bestNeighborhoodLength = tabuSolutionLength;
        bestNeigborhoodSolution = tabuSolution;
        bestGroup = random;
      }
    }
    if(bestNeighborhoodLength < std::numeric_limits<double>::max())
    {
      if(tabuList.size() >= sizeTabuList){
        tabuList.pop_front();
      }
      tabuList.push_back(bestNeigborhoodSolution);

      if (bestGroup < g1Score){
        g1Score = g1Score + p1;
      }else if (bestGroup < (g1Score+g2Score)){
        g2Score = g2Score + p1;
      }else{
        g3Score = g3Score + p1;
      }

      if(bestNeighborhoodLength < bestSolutionLength)
      {
        finalSolution = bestNeigborhoodSolution;
        bestSolutionLength = bestNeighborhoodLength;

        if (random < g1Score){
          g1Score = g1Score + p2;
        }else if (random < (g1Score+g2Score)){
          g2Score = g2Score + p2;
        }else{
          g3Score = g3Score + p2;
        }
      }
    }else{
      DEBUG("Current tabu iteration didnt improve score. No possible moves?");
    }
  }
  DEBUG("Final tabu score is "<<bestSolutionLength);
  return finalSolution;
}
void CMKGREED::getG1Solution(CoordsVectorVector& prevSol) // random shift intra-inter route
{
  //DEBUG("G1 invoked");
  int indexA1 = std::rand() % m;
  while(prevSol.at(indexA1).size() < 3)
  {
    indexA1 = std::rand() % m;
  }
  int indexC1 = (std::rand() % (prevSol.at(indexA1).size()-1)) + 1;


  Coords movedCoord = prevSol.at(indexA1).at(indexC1);
  prevSol.at(indexA1).erase(prevSol.at(indexA1).begin()+indexC1);


  if (std::rand() % 2 < 1){ // shift intra route
    int indexC2 = (std::rand() % (prevSol.at(indexA1).size())) + 1;
    while(indexC1 == indexC2){
      indexC2 = (std::rand() % (prevSol.at(indexA1).size())) + 1;
    }
    prevSol.at(indexA1).insert(prevSol.at(indexA1).begin()+indexC2, movedCoord);
  }else{ // shift inter route
    int indexA2 = std::rand() % m;
    while(indexA1 == indexA2){
      indexA2 = std::rand() % m;
    }
    int indexC2 = (std::rand() % (prevSol.at(indexA2).size())) + 1;
    prevSol.at(indexA2).insert(prevSol.at(indexA2).begin()+indexC2, movedCoord);
  }
}
void CMKGREED::getG2Solution(CoordsVectorVector& prevSol) // best shift intra-inter route based on exhaustive search
{
  //DEBUG("G2 invoked");
  int indexA1 = std::rand() % m;
  while(prevSol.at(indexA1).size() < 3)
  {
    indexA1 = std::rand() % m;
  }
  int indexC1 = (std::rand() % (prevSol.at(indexA1).size()-1)) + 1;
  Coords movedCoord = prevSol.at(indexA1).at(indexC1);
  prevSol.at(indexA1).erase(prevSol.at(indexA1).begin()+indexC1);

  double bestSolutionLength = std::numeric_limits<double>::max();
  double solutionLength;

  CoordsVectorVector intermediateSolution = prevSol;

  for(int i = 0; i < m; i++)
  {
    for(int j = 1; j <= prevSol.at(i).size(); j++)
    {
      if(!((i == indexA1) && (j == indexC1)))
      {
        intermediateSolution.at(i).insert(intermediateSolution.at(i).begin()+j,movedCoord);
        solutionLength = get_solution_cost(intermediateSolution);
        if(solutionLength < bestSolutionLength)
        {
          indexA1 = i;
          indexC1 = j;
          bestSolutionLength = solutionLength;
        }
        intermediateSolution = prevSol;
      }
    }
  }
  prevSol.at(indexA1).insert(prevSol.at(indexA1).begin()+indexC1, movedCoord);
}
void CMKGREED::getG3Solution(CoordsVectorVector& prevSol) // best swapt intra-inter route based on exhaustive search
{
  //DEBUG("G3 invoked");
  int indexA1 = std::rand() % m;
  while(prevSol.at(indexA1).size() < 3)
  {
    indexA1 = std::rand() % m;
  }
  int indexC1 = (std::rand() % (prevSol.at(indexA1).size()-1)+1);
  int indexA2;
  int indexC2;
  Coords movedCoord = prevSol.at(indexA1).at(indexC1);

  double bestSolutionLength = std::numeric_limits<double>::max();
  double solutionLength;

  CoordsVectorVector intermediateSolution = prevSol;

  for(int i = 0; i < m; i++)
  {
    for(int j = 1; j < prevSol.at(i).size(); j++)
    {
      if(!((i == indexA1) && (j == indexC1)))
      {
        std::swap(intermediateSolution[indexA1][indexC1],intermediateSolution[i][j]);
        solutionLength = get_solution_cost(intermediateSolution);
        if(solutionLength < bestSolutionLength)
        {
          indexA2 = i;
          indexC2 = j;
          bestSolutionLength = solutionLength;
        }
        intermediateSolution = prevSol;
      }
    }
  }
  std::swap(prevSol[indexA1][indexC1],prevSol[indexA2][indexC2]);
}


double CMKGREED::get_path_cost(const TargetSetPtrVector &targets)
{
   if(targets.size() < 1){
      return 0;
   }

   double len = 0;


   len += sqrt(base_coords.distance((targets.front()->inCoord());



 
       return len;
}

double CMKGREED::get_solution_cost(const TargetSetPtrVector &pts)
{
  return 0;
}

/* end of mkgreed.cc */
