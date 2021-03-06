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
		this->nodeObjects = new BraunnerPoint();
		this->depth = depth;
		this->origin = _center;
		this->halfDimension = _halfDimension;
		myBox = BoundingBox(origin-halfDimension,origin+halfDimension);
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
	if (myBox.insideBox(_t1))
		if ( BraunnerTree::getContainingOctant(_t1)==8 || depth==0)
			this->nodeObjects->insert(_t1);
		else {
			daughters[BraunnerTree::getContainingOctant(_t1)]->insert(_t1);
		}
}
int BraunnerTree::getContainingOctant(Triangle _triangle){
	int oct = 0;
	vec3 point = _triangle.a;
	if(point.x >= origin.x) oct |= 4;//Aqui determnamos se está a esquerda ou não
	if(point.y >= origin.y) oct |= 2;//Aqui, se está acima
	if(point.z >= origin.z) oct |= 1;//Aqui se está acima ou abaixo de y

	point = _triangle.b;

	int oct2=0;
	if(point.x >= origin.x) oct2 |= 4;//Aqui determnamos se está a esquerda ou não
	if(point.y >= origin.y) oct2 |= 2;//Aqui, se está acima
	if(point.z >= origin.z) oct2 |= 1;//Aqui se está acima ou abaixo de y

	if (oct!=oct2){
		return 8;
	}else {
		point = _triangle.c;
		if(point.x >= origin.x) oct |= 4;//Aqui determnamos se está a esquerda ou não
		if(point.y >= origin.y) oct |= 2;//Aqui, se está acima
		if(point.z >= origin.z) oct |= 1;//Aqui se está acima ou abaixo de y

	if (oct!=oct2)
		return 8;
	}

	return oct;
}

void BraunnerTree::getAllCollidingtrieanglesInGivenPoint(std::list<Triangle> &_listOfCandidates, Triangle _t1){

	if (depth != 0)
	{
		int NextOctant = getContainingOctant(_t1);
		nodeObjects->allElementsInThisNode(_listOfCandidates);
		if (NextOctant==8)
		{
			for (int i=0;i<8;i++){
				daughters[i]->getAllCollidingtrieanglesInGivenPoint(_listOfCandidates,_t1);
			}
		}else {
			daughters[NextOctant]->getAllCollidingtrieanglesInGivenPoint(_listOfCandidates,_t1);
		}
	}
	if (depth==0){
		nodeObjects->allElementsInThisNode(_listOfCandidates);
	}

}

BraunnerTree::~BraunnerTree() {
	// TODO Auto-generated destructor stub
	delete nodeObjects;
	for (int i =0 ; i<8 ;i++){
		delete daughters[i];
	}
}

