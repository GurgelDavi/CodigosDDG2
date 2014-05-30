/*
 * BraunnerTree.cpp
 *
 *  Created on: May 22, 2014
 *      Author: davia
 */

#include "BraunnerTree.h"

BraunnerTree::BraunnerTree(int _depth,vec3 _halfDimension, vec3 _center){

	if (_depth>=0)
	{
		this->depth = depth;
		this->origin = _center;
		this->halfDimension = _halfDimension;
		this->nodeObjects = new BraunnerPoint();
		for(int i=0; i<8; ++i)
			{
			// Calcular a nova bounding box das folhas (ou ramos)
			vec3 newOrigin = origin;
			newOrigin.x += _halfDimension.x * (i&4 ? .5f : -.5f);//SImplificação de If (i==4) .5; else -.5;
			newOrigin.y += _halfDimension.y * (i&2 ? .5f : -.5f);
			newOrigin.z += _halfDimension.z * (i&1 ? .5f : -.5f);
			this->daughters[i] = new BraunnerTree(_depth-1,_halfDimension*0.5f,newOrigin);
		}


	}
}

void BraunnerTree::insert(Triangle _t1){

}

BraunnerTree::~BraunnerTree() {
	// TODO Auto-generated destructor stub
}

