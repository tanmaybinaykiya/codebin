#ifndef __RAYTRACER_IS_INCLUDED__
#define __RAYTRACER_IS_INCLUDED__

#include <string>
#include <vector>
#include "MyMath.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"
#include "World.h"
#include "Ray.h"


class RayTracer{
private:
	World world;
	double proDist;     //projection distance
    int proWidth, proHeight, maxDepth;
public:

	RayTracer();
	RayTracer(World, double, int);

    void setWorld(World);
    void setDimension(int, int);

    Vector refract(Object*, Ray);

    Vector traceRay(Ray ray, int depth, bool shadow);
	void trace(std::string title);
};

#endif
