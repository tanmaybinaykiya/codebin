#include <iostream>
#include <cstdio>
#include "Colors.h"
#include "Check.h"



Check::Check()
{

}



Check::Check(Vector ll, Vector x, Vector y, double size, int n):Square(ll, ll+x*size, ll+x*size+y*size, ll+y*size)
{
	this->size = size;
	this->N=n;
	this->color1 = Vector(WHITE)*255;
	this->color2 = Vector(BLACK)*255;
}

void Check::setColor1(Vector col){
    this->color1 = col;
}

void Check::setColor2(Vector col){
    this->color2 = col;
}

Vector Check::getColor(Vector p)
{
    //printf("check color\n");
	int i=(int) (  projectedLength(p-this->lowerLeft,this->lowerRight-this->lowerLeft ) /(this->size/this->N) );
	int j=(int) (  projectedLength(p-this->lowerLeft,this->upperLeft-this->lowerLeft ) /(this->size/this->N) );


	if( (i^j)&1 )   return this->color1*255;
	return this->color2*255;
}

void Check::glDraw(){

}
