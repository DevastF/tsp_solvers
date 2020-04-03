#ifndef __AGENT_H__
#define __AGENT_H__

#include "target.h"
#include <vector>

namespace mkgreed {

   struct Agent {
      const int label;
      CoordsVector path;
      
      Agent(const int id) : label(id) {}
      Agent(const int id, CoordsVector pth) : label(id), path(pth) {}
   };

typedef std::vector<Agent*> AgentsPtrVector;
}

#endif