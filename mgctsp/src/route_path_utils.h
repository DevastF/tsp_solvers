/*
 * File name: route_path_utils.h
 * Date:      2016/12/10 18:12
 * Author:    Jan Faigl
 */

#ifndef __ROUTE_PATH_UTILS_H__
#define __ROUTE_PATH_UTILS_H__

#include "target.h"

double get_path_cost(const TargetSetPtrVector &pts);

double get_solution_cost(const TargetSetPtrVector &pts);

#endif

/* end of route_path_utils.h */
