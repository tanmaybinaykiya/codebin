#ifndef __SPHERE_IS_INCLUDED__
#define __SPHERE_IS_INCLUDED__

#include "MyMath.h"
#include "Vector.h"
#include "Object.h"

class Sphere : public Object{

public:
    Vector O;
    double radius;

	Sphere();
	Sphere(Vector, double);
	Sphere(Vector, double, double, double, double, Vector);

    Vector getNormal(Vector point);
    Vector reflect(Vector point, Ray ray);
    Vector intersect(Ray ray);
    Vector getColor(Vector p);
    void glDraw();
};

#endif
