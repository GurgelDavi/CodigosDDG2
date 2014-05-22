/*
 * Triangle.h
 *
 *  Created on: 20/03/2014
 *      Author: davia
 */

#ifndef Triangle_H_
#define Triangle_H_
#include "vec3.h"
class Triangle {
public:
	//Vetores que formam o triângulo
	vec3 v1,v2,cross_v1xv2; //Cross_v1xV2 == Vetor Normal
	// Pontos do triângulo
	vec3 a,b,c,center;
	//Constantes para equação do plano
	double pA,pB,pC,pD;
	Triangle();
	Triangle(vec3 _a, vec3 _b, vec3 _c);
	void plane();
	virtual ~Triangle();
};

#endif /* Triangle_H_ */
