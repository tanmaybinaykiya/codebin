#ifndef __RAY_IS_INCLUDED__
#define __RAY_IS_INCLUDED__

#include <vector>
#include "MyMath.h"
#include "Vector.h"

class Ray{
public:
	Vector origin, direction;
	
	Ray();
	Ray(Vector, Vector);
};

#endif
