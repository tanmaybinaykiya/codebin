#ifndef __CHECKERBOARD_IS_INCLUDED__
#define __CHECKERBOARD_IS_INCLUDED__

#include "MyMath.h"
#include "Vector.h"
#include "Object.h"
#include "Triangle.h"

class Checkerboard : public Triangle{

public:
    double blocksize;
    Vector X,Y;
	Vector color1;
	Vector color2;

	Checkerboard();
	Checkerboard(Vector X, Vector Y, double depth, double size);

    Vector getNormal(Vector point);
    Vector intersect(Ray ray);
    Vector getColor(Vector p);
    void glDraw();
};

#endif
