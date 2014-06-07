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
	vec3 currentMin(triangleBoxMin(_t1));
	vec3 currentMax(triangleBoxMax(_t1));
	bMax=currentMax;
	bMin=currentMin;
}

BoundingBox::~BoundingBox() {
	// TODO Auto-generated destructor stub
}
void BoundingBox::myNewForm(){//Esse método deve ser chamado a cada movimentação ou rotação de objetos dentro da bounding box
	std::vector<vec3> min;
	std::vector<vec3> max;
	for (std::list<Triangle>::iterator it = objectsInThisBox.begin();it!=objectsInThisBox.end() ; it++)
		{
		//reduzimos cada triângulo em dois vec3 com seus valores minimos e máximos para acelerar a comparação entre os pontos
		Triangle t1 = *it;
		vec3 currentMin(triangleBoxMin(t1));
		vec3 currentMax(triangleBoxMax(t1));
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
void BoundingBox::insert(Triangle _t1){
	this->objectsInThisBox.push_back(_t1);
	vec3 currentMin(triangleBoxMin(_t1));
	vec3 currentMax(triangleBoxMax(_t1));
	bMin.x = std::min (currentMin.x,bMin.x);
	bMin.y = std::min (currentMin.y,bMin.y);
	bMin.z = std::min (currentMin.z,bMin.z);

	bMax.x = std::max (currentMax.x,bMax.x);
	bMax.y = std::max (currentMax.y,bMax.y);
	bMax.z = std::max (currentMax.z,bMax.z);

}
double  BoundingBox::minOfThree(double _a,double _b,double _c){
	return std::min(std::min(_a,_b),_c);
}
double BoundingBox::maxOfThree(double _a,double _b,double _c){
	return std::max(std::max(_a,_b),_c);
}
vec3 BoundingBox::triangleBoxMax(Triangle _t1){
	return vec3(maxOfThree(_t1.a.x,_t1.b.x,_t1.c.x),maxOfThree(_t1.a.y,_t1.b.y,_t1.c.y),maxOfThree(_t1.a.z,_t1.b.z,_t1.c.z));
}

vec3 BoundingBox::triangleBoxMin(Triangle _t1){
	return vec3(minOfThree(_t1.a.x,_t1.b.x,_t1.c.x),minOfThree(_t1.a.y,_t1.b.y,_t1.c.y),minOfThree(_t1.a.z,_t1.b.z,_t1.c.z));
}
bool BoundingBox::insideBox(Triangle _t1){
	vec3 currentMin(triangleBoxMin(_t1));
	vec3 currentMax(triangleBoxMax(_t1));
	if (currentMin==bMin) return true;
	if (currentMax==bMax) return true;

	if ((bMin.x == std::min (currentMin.x,bMin.x) &&
		 bMin.y == std::min (currentMin.y,bMin.y)&&
		 bMin.z == std::min (currentMin.z,bMin.z))&&
			bMax.x == std::max (currentMax.x,bMax.x)&&
			bMax.y == std::max (currentMax.y,bMax.y)&&
			bMax.z == std::max (currentMax.z,bMax.z)
			) return true;

	return false;
}
bool BoundingBox::insideColision(Triangle _t1){
	for (std::list<Triangle>::iterator it = objectsInThisBox.begin();it!=objectsInThisBox.end() ; it++)
			{
			//reduzimos cada triângulo em dois vec3 com seus valores minimos e máximos para acelerar a comparação entre os pontos
			Triangle t1 = *it;
			bool colides = false;
			ColiderCheck col(_t1,t1,colides);
			if (colides)
				return colides;
			}
	/*Método de colisão por bounding boxes
	for (std::list<Triangle>::iterator it = objectsInThisBox.begin();it!=objectsInThisBox.end() ; it++)
	{
		Triangle t1 = *it;
		return BoundingBox(t1).insideBox(_t1);
	}
	*/
	return 0;
}



