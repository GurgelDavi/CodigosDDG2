/*
 * BraunnerTree.h
 *
 *  Created on: May 22, 2014
 *      Author: davia
 */

#ifndef BRAUNNERTREE_H_
#define BRAUNNERTREE_H_
#include "vec3.h"
#include "BraunnerPoint.h"
#include "BraunnerTree.h"
#include "BoundingBox.h"
#include <list>
#include <vector>
#include <list>
class BraunnerTree {
public:
	BraunnerTree(int _depth , vec3 _halfDimension , vec3 center);
	BraunnerTree *daughters[8];
	int depth ;
	vec3 halfDimension;
	BraunnerPoint *nodeObjects;
	vec3 origin ;
	BoundingBox myBox;
	void insert(Triangle _triangle);
	int getContainingOctant(Triangle _triangle);
	void getAllCollidingtrieanglesInGivenPoint(std::list<Triangle> &_listOfCandidates, Triangle _t1);
	virtual ~BraunnerTree();
};

#endif /* BRAUNNERTREE_H_ */
