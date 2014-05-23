/*
 * Octree.h
 *
 *  Created on: 27/03/2014
 *      Author: davia
 */

#ifndef Octree_H_
#define Octree_H_
#include "vec3.h"
#include "OctreePoint.h"
#include <cstddef>
#include <vector>
class Octree {
public:

	vec3 origin;
	vec3 halfDimension;
	//Filhos da árvore seguirão o padrão + para distãncia positiva do centro nos eixos
	// Note todos os filhos pares ficam abaixo do eixo Z
	/*Filho 0 1 2 3 4 5 6 7
	 *    x - - - - + + + +
	 * 	  y - - + + - - + +
	 *    z - + - + - + - +
	 */
	Octree *children[8];
	OctreePoint *data; //é o primeiro ponto inserido na árvore.



	Octree(const vec3& _origin, const vec3& _halfDimension) : origin(_origin),halfDimension(_halfDimension)
	{
		for (int i=0 ;i<8; ++i){
			children[i]=NULL;
		}

	}
	Octree(const Octree& _copy): origin(_copy.origin), halfDimension(_copy.halfDimension), data(_copy.data)
	{

	}
	int getContainingPointOctant(const vec3& point){
		int oct = 0;//x,y,z forem menores do que o da origem, vai para o octante 0
		if(point.x >= origin.x) oct |= 4;//Aqui determnamos se está a esquerda ou não
		if(point.y >= origin.y) oct |= 2;//Aqui, se está acima
		if(point.z >= origin.z) oct |= 1;//Aqui se está acima ou abaixo de y
		return oct;
	}

	bool isLeaf()
	{
		//Verificar se há nós após esse
		return children[0] == NULL;
	}
	void insert(OctreePoint *_point){
			//Verificar  se é um nó ou uma folha
			if (isLeaf())
			{
				//Verificar se Data está ocupado
				if (data==NULL)
				{
					data=_point;
					return;
				}else //É uma folha mas já há algo inserido
				{
					/*
					 * A partir desse ponto iremos redistribuir
					 * os dados antigos e redistribuir a árvore
					 * O primeiro  passo  é  guardar  os  dados
					 * inseridos   em   um   ponteiro  separado
					 */
					OctreePoint *oldPoint = this->data;
					this->data = NULL;
					for(int i=0; i<8; ++i)
					{
						// Calcular a nova bounding box das folhas (ou ramos)
						vec3 newOrigin = origin;
						newOrigin.x += halfDimension.x * (i&4 ? .5f : -.5f);//SImplificação de If (i==4) .5; else -.5;
						newOrigin.y += halfDimension.y * (i&2 ? .5f : -.5f);
						newOrigin.z += halfDimension.z * (i&1 ? .5f : -.5f);
						children[i] = new Octree(newOrigin, halfDimension*.5f);
					}
					// Hora de reinserir o ponto originalmente
					// na    árvore    e   o   novo   inserido
					children [getContainingPointOctant(oldPoint->getPosition())]->insert(oldPoint);
					children [getContainingPointOctant(_point->getPosition())]->insert(_point);
				}
			} else
			{
				int octant =getContainingPointOctant(_point->getPosition());
				children[octant]->insert(_point);
			}
		}
	void getPointsInsideBox(const vec3& bmin, const vec3& bmax, std::vector<OctreePoint*>& results) {

				if(isLeaf()) {
					if(data!=NULL) {
						const vec3& p = data->getPosition();
						if(p.x>bmax.x || p.y>bmax.y || p.z>bmax.z) return;
						if(p.x<bmin.x || p.y<bmin.y || p.z<bmin.z) return;
						results.push_back(data);
					}
				} else {
					for(int i=0; i<8; ++i) {

						vec3 cmax = children[i]->origin + children[i]->halfDimension;
						vec3 cmin = children[i]->origin - children[i]->halfDimension;


						if(cmax.x<bmin.x || cmax.y<bmin.y || cmax.z<bmin.z) continue;
						if(cmin.x>bmax.x || cmin.y>bmax.y || cmin.z>bmax.z) continue;

						children[i]->getPointsInsideBox(bmin,bmax,results);
					}
				}
			}


	virtual ~Octree()
	{
		for (int i=0 ;i<8; ++i){
			delete children[i];
		}
	}
};

#endif /* Octree_H_ */
