/*
 * ColiderCHeck.cpp
 *
 *  Created on: 16/04/2014
 *      Author: davia
 */

#include "ColiderCheck.h"

ColiderCheck::ColiderCheck(Triangle _t1 , Triangle _t2 ,bool &colides) {
	vec3 colisionPoint;
	colides = false;
		if (ParametricCheck(_t1,_t2.a,_t2.b,colisionPoint))
		{
			colides = true;
		}
		if (!colides){
			if (ParametricCheck(_t1,_t2.b,_t2.c,colisionPoint))
			{
				colides = true;
			}
			if (!colides){
				if (ParametricCheck(_t1,_t2.c,_t2.a,colisionPoint))
				{
					colides = true;
				}
				if (!colides){
					if (ParametricCheck(_t2,_t1.a,_t1.b,colisionPoint))
					{
						colides = true;
					}
					if (!colides){
						if (ParametricCheck(_t2,_t1.b,_t1.c,colisionPoint))
						{
							colides = true;
						}
						if (!colides){
							if (ParametricCheck(_t2,_t1.c,_t1.a,colisionPoint))
							{
								colides = true;
							}
						}
					}
				}
			}
		}




}
bool ColiderCheck::ParametricCheck(Triangle _t1, vec3 _a, vec3 _b , vec3 &_pointInPLane)
{
	_t1.plane();
	double i0 = (_t1.pA*_a.x) +(_t1.pB*_a.y)+(_t1.pC*_a.z);
	double i1 = (_t1.pA*_b.x) +(_t1.pB*_b.y)+(_t1.pC*_b.z);

	if (i0!=i1){
		double final_t = -(i1+_t1.pD)/(i0-i1);
		if (final_t<1 && (final_t>0))
		{
			double final_x = (((_a.x)*(final_t))+((_b.x)*(1-final_t)));
			double final_y = (((_a.y)*(final_t))+((_b.y)*(1-final_t)));
			double final_z = (((_a.z)*(final_t))+((_b.z)*(1-final_t)));
			_pointInPLane.x=final_x;
			_pointInPLane.y=final_y;
			_pointInPLane.z=final_z;
			return flatcheck(_t1, _pointInPLane);
		}
	}
	return false;
}

bool ColiderCheck::flatcheck(Triangle _t1 ,vec3 _p){

	if (_t1.cross_v1xv2.x>_t1.cross_v1xv2.y)
	{
		if (_t1.cross_v1xv2.x>_t1.cross_v1xv2.z)
		{
			//flat x

			Triangle tempt;

			tempt.a.x=_t1.a.y;
			tempt.a.y=_t1.a.z;

			tempt.b.x=_t1.b.y;
			tempt.b.y=_t1.b.z;

			tempt.c.x=_t1.c.y;
			tempt.c.y=_t1.c.z;

			return ColiderCheck::TwoDCheck(tempt,_p);
		}
		else
		{
			//flat z
			return ColiderCheck::TwoDCheck(_t1,_p);;;
		}
	}
	else
	{
		if (_t1.cross_v1xv2.y>_t1.cross_v1xv2.z)
		{
			//flat y

			Triangle tempt;

			tempt.a.x=_t1.a.x;
			tempt.a.y=_t1.a.z;

			tempt.b.x=_t1.b.x;
			tempt.b.y=_t1.b.z;

			tempt.c.x=_t1.c.x;
			tempt.c.y=_t1.c.z;
			return ColiderCheck::TwoDCheck(tempt,_p);
		}
		else
		{
			 //flat z
			return ColiderCheck::TwoDCheck(_t1,_p);;
		}
	}
	return true;

}
bool ColiderCheck::TwoDCheck(Triangle _t , vec3 _p){
	vec3 center(((_t.a.x+_t.b.x+_t.c.x)/3),((_t.a.y+_t.b.y+_t.c.y)/3),(0));
	bool ab,bc,ca = false;
	ab=linecheck(_t.a , _t.b ,center , _p);
	bc=linecheck(_t.b , _t.c ,center , _p);
	ca=linecheck(_t.c , _t.a ,center , _p);

	return ab*bc*ca;
}
bool ColiderCheck::linecheck(vec3 _a , vec3 _b , vec3 center, vec3 _p ){
	float m = ((_b.y-_a.y)/(_b.x-_a.x));
	float b =((_a.y/(m*_a.x)));

	float ya = m*_a.x + b;

	float parameterC =((m*center.x)+b);

	float waldo = ((m*_p.x)+b);

	parameterC = parameterC - ya;
	waldo = waldo - ya;
	if (waldo*parameterC<0)
		return false;
	return true;
}



ColiderCheck::~ColiderCheck() {
	// TODO Auto-generated destructor stub
}

