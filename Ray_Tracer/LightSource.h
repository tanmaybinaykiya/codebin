#ifndef __LIGHT_SOURCE_IS_INCLUDED__
#define __LIGHT_SOURCE_IS_INCLUDED__

#include "MyMath.h"
#include "Sphere.h"

class LightSource : public Sphere{

public:
    double intensity;
	LightSource();
	LightSource(Vector, double, double);
};

#endif
