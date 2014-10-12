#ifndef __SQUARE_IS_INCLUDED__
#define __SQUARE_IS_INCLUDED__

#include "MyMath.h"
#include "Vector.h"
#include "Object.h"
#include "Triangle.h"

class Square : public Object{

public:
    Vector lowerLeft;
	Vector lowerRight;
	Vector upperLeft;
	Vector upperRight;
	Triangle lowerTriangle;
	Triangle upperTriangle;
	Square();
	Square(Vector,Vector,Vector,Vector);
    Vector getNormal(Vector point);
    Vector reflect(Vector point, Ray ray);
    Vector intersect(Ray ray);
    Vector getColor(Vector p);
    void glDraw();
};

#endif

