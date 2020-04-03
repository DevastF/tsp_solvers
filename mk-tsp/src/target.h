/*
 * File name: target.h
 * Date:      2016/12/09 07:55
 * Author:    Jan Faigl
 */

#ifndef __TARGET_H__
#define __TARGET_H__

#include "coords.h"
#include "agent.h"

namespace mkgreed {

   struct STarget {
      const int label;
      const Coords coords;
      Agent* visitedBy;

      STarget(const int id, const Coords pt) : label(id), coords(pt), visitedBy(nullptr) {}
      STarget(const int id, const Coords pt, Agent* vs) : label(id), coords(pt), visitedBy(vs) {}
   };

   typedef std::vector<STarget*> TargetPtrVector;

} // end namespace mkgreed

#endif

/* end of target.h */
