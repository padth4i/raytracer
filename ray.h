#ifndef RAYH
#define RAYH
#include "vec3.h"

class ray {
public:
	ray(const vec3& origin, const vec3& direction) {
		A = origin;
		B = direction;
		}

	vec3 origin() const { return A; }
	vec3 direction() const { return B; }
	vec3 ray_parameter(float t) const { return A + B*t; }

	vec3 A, B;
};
#endif
