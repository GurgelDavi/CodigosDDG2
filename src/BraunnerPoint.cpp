/*
 * BraunnerPoint.cpp
 *
 *  Created on: May 22, 2014
 *      Author: davia
 */

#include "BraunnerPoint.h"
#include <iostream>
#include <vector>

BraunnerPoint::BraunnerPoint() {




}
void BraunnerPoint::insert(Triangle _t1){
	this->trianglesInThisNode.push_back(_t1);
}
void BraunnerPoint::allElementsInThisNode(std::list<Triangle> &_list){
	//for(auto it = std::begin(this->allElementsInThisNode()); it!=std::end(this->allElementsInThisNode()); ++it)
	  //  _list.push_back(*it);
	//std::list<Triangle>::iterator it = trianglesInThisNode.begin();
	for (std::list<Triangle>::iterator it = trianglesInThisNode.begin();it!=trianglesInThisNode.end() ; it++)
	{
		_list.push_back(*it);
	}

}
BraunnerPoint::~BraunnerPoint() {
	// TODO Auto-generated destructor stub
}

