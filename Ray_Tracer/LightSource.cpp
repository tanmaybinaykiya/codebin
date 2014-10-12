#include "LightSource.h"


LightSource::LightSource(){
    this->type = "light";
	this->O = Vector(0,0,0);
	this->radius = 0.;
	this->intensity = 1.;
}

LightSource::LightSource(Vector pos, double rad, double em):Sphere(pos, rad){
	this->type = "light";
	this->O = pos;
	this->radius = rad;
	this->intensity = em;
}

