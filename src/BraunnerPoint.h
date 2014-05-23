/*
 * BraunnerPoint.h
 *
 *  Created on: May 22, 2014
 *      Author: davia
 */

#ifndef BRAUNNERPOINT_H_
#define BRAUNNERPOINT_H_
#include "Triangle.h"
#include <list>
#include <vector>
class BraunnerPoint {
public:
	std::list <Triangle> trianglesInThisNode;
	BraunnerPoint();
	virtual ~BraunnerPoint();
};

#endif /* BRAUNNERPOINT_H_ */
