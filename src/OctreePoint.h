/*
 * OctreePoint.h
 *
 *  Created on: 31/03/2014
 *      Author: davia
 */

#ifndef OCTREEPOINT_H_
#define OCTREEPOINT_H_
#include "vec3.h"


class OctreePoint {
public:
	vec3 position;

	OctreePoint() { }
	OctreePoint(const vec3& position) : position(position) { }
	inline const vec3& getPosition() const { return position; }
	inline void setPosition(const vec3& p) { position = p; }
};

#endif /* OCTREEPOINT_H_ */
