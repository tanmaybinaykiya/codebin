#include "mygl.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include "Sphere.h"


Sphere::Sphere(){
    this->type = "sphere";
}

Sphere::Sphere(Vector o, double r){
    this->type = "sphere";
    this->O = o;
    this->radius = r;
    this->RF = 0.;
}

Sphere::Sphere(Vector o, double r, double s, double t, double ri, Vector col){
    this->type = "sphere";
    this->O = o;
    this->radius = r;
    this->S = s;
    this->T = t;
    this->RI = ri;
    this->color = col;
}

Vector Sphere::getNormal(Vector point){
    Vector dist = (point - this->O);
    //if( fabs(dist.mag()-this->radius) > EPS )   return Vector(0,0,0);
    dist.norm();
    return dist;
}

Vector Sphere::reflect(Vector point, Ray ray){
    //R = I - 2*(N.I)*N
    Vector I = ray.direction;
    Vector N = this->getNormal(point);

    Vector d = (ray.origin - this->O);
    if(DOT(N, I) > 0)   N =-N;

    Vector R = I - 2*DOT(N, I)*N;
    R.norm();

    //assert(DOT(N, R) > 0);
    return R;
}

Vector Sphere::intersect(Ray ray){
    //(Rd·Rd)*t^2 + 2Rd·Ro*t + Ro·Ro - r^2  =  0
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

    return Vector(ray.origin + Rd*t);

}

Vector Sphere::getColor(Vector p){

    return this->color*255;
}

void Sphere::glDraw(){
    glPushMatrix();
        glTranslatef( CO( this->O) );
        glColor3f( CO( Vector(this->color) ) );
        glutSolidSphere( this->radius, 20, 20);
    glPopMatrix();
}
