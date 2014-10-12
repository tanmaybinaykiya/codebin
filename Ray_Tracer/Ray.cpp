#include "Ray.h"


Ray::Ray(){
	this->direction = this->origin = Vector(0,0,0);
}


Ray::Ray(Vector o, Vector d){
	this->origin = o;
	this->direction = d;
	this->direction.norm();
}
