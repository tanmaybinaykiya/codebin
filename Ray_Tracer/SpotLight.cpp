#include "SpotLight.h"
#include <cstdio>


SpotLight::SpotLight(){
    this->type = "light";
	this->O = Vector(0,0,0);
	this->radius = 0.;
	this->intensity = 1.;
}

SpotLight::SpotLight(Vector pos, Vector dir, double sp, double in):LightSource(pos, 1., in){
	this->type = "light";
	this->O = pos;
	this->direction = dir;
	this->span = sp;
	this->intensity = in;
}

Vector SpotLight::intersect(Ray ray){
    Vector Ro = ray.origin - this->O;
    Vector Rd = ray.direction;
    Rd.norm();

    double a = DOT(Rd, Rd);
    double b = 2*DOT(Rd, Ro);
    double c = DOT(Ro, Ro) - this->radius*this->radius;

    double d2 =  b*b - 4*a*c ;

    if(d2 < 0)  return Vector(INFP);

    double d = sqrt(d2);

    double t1 = (-1*b - d)/(2*a);
    double t2 = (-1*b + d)/(2*a);
    //printf("%g %g\n",t1,t2);
    double t;

    if(t1<0 && t2<0)     return Vector(INFP);
    else if(t1 < 0)  t = t2;
    else if(t2 < 0) t = t1;
    else if(t1 < t2) t = t1;
    else t = t2;

    if(t <= EPS)    return Vector(INFP);

    double sp = ( acos( DOT(-Rd, this->direction) ) / (Rd.mag() * this->direction.mag()) ) * (180 / PI);
    printf("span: %.2lf\n",sp);
    if(sp > this->span) return Vector(INFP);

    //return Vector(INFP);

    return Vector(ray.origin + Rd*t);

}
