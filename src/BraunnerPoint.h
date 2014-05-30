/*
 * BraunnerPoint.h
 *
 *  Created on: May 22, 2014
 *      Author: davia
 */

#ifndef BRAUNNERPOINT_H_
#define BRAUNNERPOINT_H_
#include <iostream>
#include "Triangle.h"
#include <list>
#include <vector>

class BraunnerPoint {
public:
	std::list<Triangle> trianglesInThisNode;
	BraunnerPoint();
	void insert(Triangle _t1);
void allElementsInThisNode (std::list<Triangle> &_list);
	virtual ~BraunnerPoint();
};

#endif /* BRAUNNERPOINT_H_ */
