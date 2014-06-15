/*
 * LodObject.h
 *
 *  Created on: Jun 15, 2014
 *      Author: davia
 */

#ifndef LODOBJECT_H_
#define LODOBJECT_H_
#include "Triangle.h"
#include <list>
class LodObject {
public:
	double distance;
	bool lowResDisplay;
	vec3 camera;
	vec3 myCenterPos;
	std::list<Triangle> mesh1;
	std::list<Triangle> mesh2;
	LodObject(std::list<Triangle> _meshList1,std::list<Triangle> _meshList2, vec3 _cam, vec3 _myPos);
	double updateDist();
	void displayMesh(std::list<Triangle> &_meshList);
	int nowDisplaying();
	virtual ~LodObject();
};

#endif /* LODOBJECT_H_ */
