/*
 * BoundingBox.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: davia
 */

#include "BoundingBox.h"

BoundingBox::BoundingBox(Triangle _t1) {
	this->objectsInThisBox.push_back(_t1);
	//double x = std::min((std::min(_t1.a.x,_t1.b.x)),_t1.c.x);
	//double y = std::min((std::min(_t1.a.y,_t1.b.y)),_t1.c.y);
	//double z = std::min((std::min(_t1.a.z,_t1.b.z)),_t1.c.z);
	vec3 currentMin(std::min((std::min(_t1.a.x,_t1.b.x)),_t1.c.x),//xMin
			std::min((std::min(_t1.a.y,_t1.b.y)),_t1.c.y),//yMin
			std::min((std::min(_t1.a.z,_t1.b.z)),_t1.c.z));//zMin
	vec3 currentMax(std::max((std::max(_t1.a.x,_t1.b.x)),_t1.c.x),//x
				std::max((std::max(_t1.a.y,_t1.b.y)),_t1.c.y),//y
				std::max((std::max(_t1.a.z,_t1.b.z)),_t1.c.z));//z
	bMax=currentMax;
	bMin=currentMin;



}

BoundingBox::~BoundingBox() {
	// TODO Auto-generated destructor stub
}
void BoundingBox::myNewForm(){
	std::vector<vec3> min;
	std::vector<vec3> max;
	for (std::list<Triangle>::iterator it = objectsInThisBox.begin();it!=objectsInThisBox.end() ; it++)
		{
		//reduzimos cada triângulo em dois vec3 com seus valores minimos e máximos para acelerar a comparação entre os pontos
		Triangle t1 = *it;
		vec3 currentMin(std::min((std::min(t1.a.x,t1.b.x)),t1.c.x),//xMin
					std::min((std::min(t1.a.y,t1.b.y)),t1.c.y),//yMin
					std::min((std::min(t1.a.z,t1.b.z)),t1.c.z));//zMin
			vec3 currentMax(std::max((std::max(t1.a.x,t1.b.x)),t1.c.x),//x
						std::max((std::max(t1.a.y,t1.b.y)),t1.c.y),//y
						std::max((std::max(t1.a.z,t1.b.z)),t1.c.z));//z
		min.push_back(currentMin);
		max.push_back(currentMax);
		}
	bMin = smallest(min);
	bMax = biggest(max);
}

vec3 BoundingBox::smallest(std::vector<vec3> v){
	double x = std::numeric_limits<double>::max();
	double y = std::numeric_limits<double>::max();
	double z = std::numeric_limits<double>::max();
	for (int i=0 ; i<v.size();i++ ){
		x = std::min(x , v[i].x);
		y = std::min(y , v[i].y);
		z = std::min(z , v[i].z);
	}

	return vec3(x,y,z);
}

vec3 BoundingBox::biggest(std::vector<vec3> v){
	double x = std::numeric_limits<double>::min();
	double y = std::numeric_limits<double>::min();
	double z = std::numeric_limits<double>::min();
	for (int i=0 ; i<v.size();i++ ){
		x = std::max(x , v[i].x);
		y = std::max(y , v[i].y);
		z = std::max(z , v[i].z);
	}

	return vec3(x,y,z);
}
