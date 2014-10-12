#ifndef __TRIANGLE_IS_INCLUDED__
#define __TRIANGLE_IS_INCLUDED__

#include "MyMath.h"
#include "Vector.h"
#include "Object.h"

class Triangle : public Object{

public:
    Vector A;
	Vector B;
	Vector C;
	Triangle();
	Triangle(Vector,Vector,Vector);
    Vector getNormal(Vector point);
    Vector reflect(Vector point, Ray ray);
    Vector intersect(Ray ray);
    Vector getColor(Vector p);
    void glDraw();
};

#endif
