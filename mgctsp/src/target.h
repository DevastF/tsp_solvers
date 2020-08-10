/*
 * File name: target.h
 * Date:      2016/12/09 07:55
 * Author:    Jan Faigl
 */

#ifndef __TARGET_H__
#define __TARGET_H__

#include "../../../../CLionProjects/PowerlineTSP/src/coords.h"
#include "agent.h"

   struct TargetSet {
      int inCoordIndex;
      const std::vector<Coords> coords;
      bool visited;
      double cost;

      TargetSet(const int i, const std::vector<Coords> pts) : inCoordIndex(i), coords(pts), visited(false), cost(pts.front().distance(pts.back())) {}
      TargetSet(const int i, const std::vector<Coords> pts, const bool v) : inCoordIndex(i), coords(pts), visited(v), cost(pts.front().squared_distance(pts.back())) {}
  
   inline Coords outCoord(){
      return coords.at((inCoordIndex+1)%2); 
   }

   inline Coords inCoord(){
      return coords.at(inCoordIndex); 
   }

   inline void reverse(){
      inCoordIndex = (inCoordIndex+1)%2;
   }

  inline double squared_distance_to(TargetSet destination){
    return this->outCoord().squared_distance(destination.inCoord());
  }

   };


   typedef std::vector<TargetSet*> TargetSetPtrVector;
   typedef std::vector<std::vector<TargetSet*>> TargetSetPtrVectorVector;


#endif

/* end of target.h */
