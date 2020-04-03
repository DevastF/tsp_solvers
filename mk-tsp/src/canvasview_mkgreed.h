/*
 * File name: canvasview_mkgreed.h
 * Date:      2016/12/09 08:01
 * Author:    Jan Faigl
 */

#ifndef __CANVASVIEW_GSOA_H__
#define __CANVASVIEW_GSOA_H__

#include <vector>

#include <boost/foreach.hpp>

#include <crl/gui/gui.h>
#include <crl/gui/colors.h>
#include <crl/gui/renderer.h>
#include <crl/gui/canvas.h>

namespace mkgreed {
   typedef std::vector<mkgreed::STarget*> TargetPtrVector;
} // end namespace mkgreed

/// ----------------------------------------------------------------------------
inline crl::gui::CCanvasBase& operator<<(crl::gui::CCanvasBase &canvas, const mkgreed::STarget &target) 
{
   canvas << target.coords.x << target.coords.y;
   return canvas;
}

/// ----------------------------------------------------------------------------
inline crl::gui::CCanvasBase& operator<<(crl::gui::CCanvasBase &canvas, const mkgreed::TargetPtrVector &targets)
{
   BOOST_FOREACH(const mkgreed::STarget *target, targets) {
      canvas << target->coords.x << target->coords.y;
   }
   return canvas;
}


#endif

/* end of canvasview_mkgreed.h */
