#include "World.h"



World::World(){
    this->nL = this->nObj = 0;
    this->RI = 1.;
}

World::World(Vector x, Vector y, Vector z, double amb){
    this->I = x;
    this->J = y;
    this->K = z;
    this->nL = this->nObj = 0;
    this->RI = 1.;
    this->ambient = amb;
}

std::vector<Object*> World::getObjects(){
    return this->worldObjects;
}

void World::setCamera(Camera c){
    this->camera = c;
}

void World::setRI(int ri){
    this->RI = ri;
}

void World::addObject(Object* obj){
    this->worldObjects.push_back(obj);
    this->nObj++;
}

Object* World::getObject(unsigned int i){
    if(i >= this->worldObjects.size())  return NULL;
    return this->worldObjects[i];
}


void World::addLightSource(LightSource* ls){
    this->lights.push_back(ls);
    this->nL++;
}

LightSource* World::getLightSource(unsigned int i){
    if(i >= this->lights.size())  return NULL;
    return this->lights[i];
}
