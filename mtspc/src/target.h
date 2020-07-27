/*
 * File name: target.h
 * Date:      2016/12/09 07:55
 * Author:    Jan Faigl
 */

#ifndef __TARGET_H__
#define __TARGET_H__

#include "coords.h"
#include "agent.h"

namespace graspc {

   struct STarget {
      const int label;
      const Coords coords;
      bool visited;

      STarget(const int id, const Coords pt) : label(id), coords(pt), visited(false) {}
      STarget(const int id, const Coords pt, bool vs) : label(id), coords(pt), visited(vs) {}
   };

   typedef std::vector<STarget*> TargetPtrVector;

} // end namespace mkgreed

#endif

/* end of target.h */
