#ifndef __SPOT_LIGHT_IS_INCLUDED__
#define __SPOT_LIGHT_IS_INCLUDED__

#include "MyMath.h"
#include "Sphere.h"
#include "LightSource.h"

class SpotLight : public LightSource{

public:
    Vector direction;
    double span;
	SpotLight();
	SpotLight(Vector, Vector, double, double);
	Vector intersect(Ray ray);
};

#endif
