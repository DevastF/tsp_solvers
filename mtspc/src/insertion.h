
#ifndef __INSERTION_H__
#define __INSERTION_H__

struct Insertion{
    double SolutionCost;
    int Target;
    int Agent;
    int InsertIndex;

    Insertion(double l, int t, int a, int i) : SolutionCost(l), Target(t), Agent(a), InsertIndex(i) {}

    // not used atm
    bool operator()(Insertion const & a, Insertion const & b) const
    {
        return a.SolutionCost < b.SolutionCost;
    }
};

struct InsComp{
  
  bool operator()(const Insertion* a, const Insertion* b) const  
  { 
      return a->SolutionCost < b->SolutionCost;
  }

};

#endif
