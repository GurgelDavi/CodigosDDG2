/*
 * LodObject.cpp
 *
 *  Created on: Jun 15, 2014
 *      Author: davia
 */

#include "LodObject.h"

LodObject::LodObject(std::list<Triangle> _meshList1,std::list<Triangle> _meshList2, vec3 _cam, vec3 _myPos,double _dist) :
mesh1(_meshList1),mesh2(_meshList2),camera(_cam) , myCenterPos(_myPos), distance(_dist){

}
double LodObject::updateDist(){

	double d= std::sqrt((myCenterPos.x - camera.x)*(myCenterPos.x - camera.x) +
							(myCenterPos.y - camera.y)*(myCenterPos.y - camera.y) +
								(myCenterPos.z - camera.z)*(myCenterPos.z - camera.z) );
	if (d > distance)
			lowResDisplay=true;
	if (d <= distance)
			lowResDisplay=false;
	return d;
}
void LodObject::displayMesh(std::list<Triangle> &_meshList){
	if (lowResDisplay)
		_meshList = mesh1;
	else _meshList = mesh2;
}
int LodObject::nowDisplaying(){// For tests only
	if (lowResDisplay)
		return 1;
	else return 2;
}

LodObject::~LodObject() {
	// TODO Auto-generated destructor stub
}

