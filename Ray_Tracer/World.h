#ifndef __WORLD_IS_INCLUDED__
#define __WORLD_IS_INCLUDED__

#include <cstdlib>
#include <vector>
#include "MyMath.h"
#include "Object.h"
#include "Camera.h"
#include "LightSource.h"

class World{
	Vector I, J, K;
	std::vector<Object*> worldObjects;
	std::vector<LightSource*> lights;
public:

	Camera camera;
	int nObj, nL;
	double ambient;

	World();
	World(Vector, Vector, Vector, double);

	double RI;
	std::vector<Object*> getObjects();
	std::vector<LightSource*> getLights();

	void addObject(Object*);
	Object* getObject(unsigned int i);

	void addLightSource(LightSource*);
	LightSource* getLightSource(unsigned int i);

	void setCamera(Camera);

	void setRI(int ri);
};

#endif
