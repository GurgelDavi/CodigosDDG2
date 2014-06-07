/*
 * BoundingBox.h
 *
 *  Created on: Jun 6, 2014
 *      Author: davia
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_
#include "Triangle.h"
#include <list>
#include "vec3.h"
#include <vector>
#include <limits>
#include "ColiderCheck.h"
class BoundingBox {
public:
	std::list<Triangle> objectsInThisBox;
	vec3 bMin,bMax;
	BoundingBox(Triangle _t1);
	BoundingBox(std::list<Triangle> _list);
	void insert(Triangle _t);
	int insert(std::list<Triangle> _list);
	void myNewForm();
	vec3 smallest(std::vector<vec3>);
	vec3 biggest(std::vector<vec3>);
	double minOfThree(double a,double b, double c);
	double maxOfThree(double a,double b, double c);
	vec3 triangleBoxMin(Triangle _t1);
	vec3 triangleBoxMax(Triangle _t1);
	bool insideBox(Triangle _t1);
	bool insideColision(Triangle _t1);

	virtual ~BoundingBox();
};

#endif /* BOUNDINGBOX_H_ */
