#include "mygl.h"
#include <iostream>
#include <cstdio>
#include "MyMath.h"
#include "Square.h"

Square::Square()
{

}

Square::Square(Vector lowerLeft,Vector lowerRight,Vector upperRight,Vector upperLeft)
{
	this->lowerLeft=lowerLeft;
	this->lowerRight=lowerRight;
	this->upperLeft=upperLeft;
	this->upperRight=upperRight;
	this->lowerTriangle=Triangle(lowerLeft, lowerRight, upperLeft);
	this->upperTriangle=Triangle(upperLeft, lowerRight, upperRight);
}


Vector Square::getNormal(Vector point)
{
    Vector N = CROSS(this->lowerLeft-point, this->lowerRight-point);
    N.norm();
	return N;
}

Vector Square::reflect(Vector point, Ray ray)
{
    if(upperTriangle.intersect(ray)==Vector(INFP))  return lowerTriangle.reflect(point, ray);
    return upperTriangle.reflect(point, ray);
}


Vector Square::intersect(Ray ray)
{
    //printf("square intersect\n");
	if(lowerTriangle.intersect(ray)==Vector(INFP))
		return upperTriangle.intersect(ray);
	return lowerTriangle.intersect(ray);
}



Vector Square::getColor(Vector p){
    //printf("square color\n");
    return this->color*255;
}

void Square::glDraw(){
    glPushMatrix();
        this->lowerTriangle.glDraw();
        this->upperTriangle.glDraw();
    glPopMatrix();
}
