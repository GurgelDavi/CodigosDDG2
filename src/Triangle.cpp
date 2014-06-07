/*
 * Triangle.cpp
 *
 *  Created on: 20/03/2014
 *      Author: davia
 */

#include "Triangle.h"

Triangle::Triangle()
		{
		}
Triangle::Triangle(vec3 _a, vec3 _b, vec3 _c)
		//a(_a), b(_b), c(_c), center(center((_a.x+_b.x+_c.x)/3),((_a.y+_b.y+_c.y)/3),((_a.z+_b.z+_c.z)/3))
		{
			a=_a;
			b=_b;
			c=_c;
			center=_a+_b+_c;
			center=(center/3);
		}
void Triangle::plane()
	{
		v1 = b - c;
		v2 = c - a;
		cross_v1xv2 = v1.cross(v2);
		pA = cross_v1xv2.x;
		pB = cross_v1xv2.y;
		pC = cross_v1xv2.z;
		pD = cross_v1xv2.dot(center);
	}
Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

