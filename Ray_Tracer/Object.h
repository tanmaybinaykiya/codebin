#ifndef __OBJECT_IS_INCLUDED__
#define __OBJECT_IS_INCLUDED__

#include <iostream>
#include <cstring>
#include "MyMath.h"
#include "Vector.h"
#include "Ray.h"

class Object{

public:
    double S, RI, RF, T;
    Vector color;
    std::string type;

	Object(){};
    virtual Vector getNormal(Vector point)=0;
    virtual Vector reflect(Vector point, Ray ray)=0;
    virtual Vector intersect(Ray ray)=0;
    virtual Vector getColor(Vector p)=0;
    virtual void glDraw()=0;
};

#endif
