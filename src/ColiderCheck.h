/*
 * ColiderCHeck.h
 *
 *  Created on: 16/04/2014
 *      Author: davia
 */

#ifndef COLIDERCHECK_H_
#define COLIDERCHECK_H_
#include "vec3.h"
#include "Triangle.h"
class ColiderCheck {
public:

	ColiderCheck(Triangle _t1 , Triangle _t2 ,bool &colides);
	bool ParametricCheck(Triangle _t1, vec3 _a, vec3 _b , vec3 &_pointInPLane );
	bool flatcheck(Triangle _t1 , vec3 _p);
	bool TwoDCheck(Triangle _t , vec3 _p);
	bool linecheck(vec3 _a,vec3 _b, vec3 center , vec3 _p);
	virtual ~ColiderCheck();
};

#endif /* COLIDERCHECK_H_ */
