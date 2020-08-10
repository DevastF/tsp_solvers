#ifndef __AGENT_H__
#define __AGENT_H__

#include "target.h"
#include <vector>

namespace graspc {

   struct Agent {
      const int label;
      TargetSetPtrVector path;
      
      Agent(const int id) : label(id) {}
      Agent(const int id, TargetSetPtrVector pth) : label(id), path(pth) {}
   };

typedef std::vector<Agent*> AgentsPtrVector;
}

#endif
