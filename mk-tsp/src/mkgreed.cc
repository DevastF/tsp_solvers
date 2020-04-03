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

#include "mkgreed.h"

#include "route_path_utils.h"

#include "canvasview_coords.h"
#include "canvasview_mkgreed.h"

#define foreach BOOST_FOREACH

using namespace mkgreed;

typedef std::vector<int> IntVector;

using namespace crl;
using namespace crl::gui;

/// ----------------------------------------------------------------------------
static void createPermutation(int number, IntVector &permutation) 
{
   permutation.clear();
   for (int i = 0; i < number; i++) {
      permutation.push_back(i);
   }
}

/// ----------------------------------------------------------------------------
static void permute(IntVector &permutation) 
{
   int k, tmp;
   for (int i = permutation.size(); i > 0; --i) {
      k = crl::CRandom::random() % i;
      tmp = permutation[i - 1];
      permutation[i - 1] = permutation[k];
      permutation[k] = tmp;
   }
}

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

   config.add<int>("m-agents", "Number of agents", 1);
   config.add<int>("k-nodes", "Number of nodes to explore", 10);
   config.add<int>("start-node-id", "Id of node where to begin search", 0);

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
   m(config.get<int>("m-agents")),
   k(config.get<int>("k-nodes")),
   startNode(config.get<int>("start-node-id"))
{
   shapeTargets.setShape(config.get<std::string>("draw-shape-targets"));
   shapePath.setShape(config.get<std::string>("draw-shape-path"));
   shapePathNodes.setShape(config.get<std::string>("draw-shape-path-nodes"));
   method = config.get<std::string>("method");

   for(int i = 0; i < m; ++i){
      agents.push_back(new Agent(agents.size()));
   }
   const std::string fname = config.get<std::string>("problem");
   { // load problem
      std::ifstream in(fname);
      Coords pt;
      while (in >> pt) {
         targets.push_back(new STarget(targets.size(), pt));
      }
   }

   for(Agent *agent : agents)
   {
      agent->path.push_back(targets.at(startNode)->coords);
      targets.at(startNode)->visitedBy = agent;
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
   foreach(Agent *agent, agents) {
      delete agent;
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
   crl::CRandom::randomize();
   finalSolution.clear();

   if (canvas) {
      *canvas << canvas::CLEAR << "path" << "path";
   }
   
   int step = 0;

   double bestSolutionLength = std::numeric_limits<double>::max();
   bool term = false;

   double cost;
   int bestAgent;
   int bestTarget;
   CoordsVector costCoords;
   std::string debug;

   while ((step < k) && not term) { //perform adaptation step

      DEBUG("Step: " << step);

      bestSolutionLength = std::numeric_limits<double>::max();

      for(int i = 0; i < targets.size(); i++){
         if(targets.at(i)->visitedBy == nullptr){
            for(int j = 0; j < agents.size(); j++){
               costCoords = agents.at(j)->path;
               cost = targets.at(i)->coords.squared_distance(costCoords.back()) + targets.at(i)->coords.squared_distance(targets.at(startNode)->coords);
               if(cost < bestSolutionLength){
                  bestSolutionLength = cost;
                  bestTarget = i;
                  bestAgent = j;
               }
            }
         }   
      }

      targets.at(bestTarget)->visitedBy = agents.at(bestAgent);
      agents.at(bestAgent)->path.push_back(targets.at(bestTarget)->coords);

      debug = "Solution: Agent "+std::to_string(agents.at(bestAgent)->label)+" Node "+std::to_string(targets.at(bestTarget)->label)+" "+std::to_string(targets.at(bestTarget)->coords.x)+" "+std::to_string(targets.at(bestTarget)->coords.y);
      DEBUG(debug);
      debug = "Was saved: Agent "+std::to_string(targets.at(bestTarget)->visitedBy->label)+" Node "+std::to_string(targets.at(bestTarget)->label)+" "+std::to_string(agents.at(bestAgent)->path.back().x)+" "+std::to_string(agents.at(bestAgent)->path.back().y);
      DEBUG(debug);

      /*if (BEST_SOLUTION) {
         getSolution(step, solution); //collect solution
         const double len = get_path_length(solution);
         if (len < bestSolutionLength) {
            bestSolution = solution;
            bestSolutionStep = step;
            bestSolutionLength = len;
         }
      }
      if (TERM_CHANGE) {
         ring->get_ring_route(step, routes[routeCur]);
         if (routes[routeCur].size() == routes[routePrev].size()) {
            term = true;
            for (int i = 0; i < routes[routeCur].size(); ++i) {
               if (routes[routeCur][i] != routes[routePrev][i]) {
                  term = false;
                  break;
               }
            }
         }
         routePrev = (routePrev + 1)%2;
         routeCur = (routeCur + 1)%2;
      }*/

      step++;
   } //end step loop
   tSolve.stop();

  /* double length;
   if (BEST_SOLUTION) {
      finalSolution = bestSolution;
      length = bestSolutionLength;
      finalBestSolutionStep = bestSolutionStep;
   } else {
      getSolution(step - 1, finalSolution); //collect solution
      length = get_path_length(finalSolution);
      finalBestSolutionStep = step - 1;
   }

   if (config.get<bool>("2opt-post")) {
      two_opt(finalSolution);
      double twoOptLength = get_path_length(finalSolution);
      DEBUG("Length: " << length << " after 2opt: " << twoOptLength);
      length = twoOptLength;
   }
   fillResultRecord(iter);*/
   /*resultLog
     // << length // 
      << step
      //<< finalBestSolutionStep
      << crl::result::endrec;*/
   //DEBUG("Best solution with the length: " << bestSolutionLength << " found in: " << bestSolutionStep << " steps");
}

/// - protected method ---------------------------------------------------------
double CMKGREED::refine(int step, double errorMax)
{
   double errorToGoal = errorMax;
   double error = 0.0;
   /*permute(permutation);
   schema->updateExp(targets.size(), step);
   for (IntVector::iterator i = permutation.begin(); i != permutation.end(); i++) {
      STarget *target = targets[*i];
      SNeuron *prevWinner = target->stepWinnerSelected == step - 1 ? target->selectedWinner : 0;
      int r = 0;
      SWinnerSelection* winner = ring->selectWinner(step, target, errorToGoal);
      if (winner and winner->hasWinner) {
         ring->adapt(step); 
         if (error < errorToGoal) {
            error = errorToGoal; //update error
         }
      }
   } //end permutation of all targets
   ring->regenerate(step);
   if (canvas and DRAW_RING_ITER) {
      drawRing(step);
      if (SAVE_PIC) {
         savePic(step, true);
      }
   }*/
   return error; // return largest error to city
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
      foreach(const Agent* agent, agents){
         foreach(const Coords pt, agent->path) {
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
   foreach(Agent* agent, agents){
      foreach(Coords coords, agent->path){
         path.push_back(coords);
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

/// - private method -----------------------------------------------------------
void CMKGREED::getSolution(int step, CoordsVectorVector &solution) const
{
   //ring->get_ring_path(step, solution);
}

/* end of mkgreed.cc */
