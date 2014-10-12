#include "mygl.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include "Colors.h"
#include "Checkerboard.h"


Checkerboard::Checkerboard()
{

}

Checkerboard::Checkerboard(Vector X, Vector Y, double depth, double size){
	this->blocksize = size;
	this->color = Vector(RED);
	this->X = X;
	this->Y = Y;

    Vector Z =  -CROSS(X,Y)*depth;
	this->A =  X*0 + Z;
	this->B =  X*10 + Z;
	this->C =  Y*10 + Z;

}


Vector Checkerboard::getNormal(Vector point)
{
	Vector AB = this->B - this->A;
	Vector AC = this->C - this->A;
    Vector N = CROSS(X, Y);
    N.norm();
	return N;
}


Vector Checkerboard::intersect(Ray ray)
{
	double A=(((this->A.x-this->B.x)*((this->A.y-this->C.y)*ray.direction.z-(this->A.z-this->C.z)*ray.direction.y))+
			 ((this->A.x-this->C.x)*((this->A.z-this->B.z)*ray.direction.y-(this->A.y-this->B.y)*ray.direction.z))+
			 (ray.direction.x*((this->A.y-this->B.y)*(this->A.z-this->C.z)-(this->A.z-this->B.z)*(this->A.y-this->C.y))));


	double beta=(((this->A.x-ray.origin.x)*((this->A.y-this->C.y)*ray.direction.z-(this->A.z-this->C.z)*ray.direction.y))+
			 ((this->A.x-this->C.x)*((this->A.z-ray.origin.z)*ray.direction.y-(this->A.y-ray.origin.y)*ray.direction.z))+
			 (ray.direction.x*((this->A.y-ray.origin.y)*(this->A.z-this->C.z)-(this->A.z-ray.origin.z)*(this->A.y-this->C.y))))/A;

	double gamma=(((this->A.x-this->B.x)*((this->A.y-ray.origin.y)*ray.direction.z-(this->A.z-ray.origin.z)*ray.direction.y))+
				 ((this->A.x-ray.origin.x)*((this->A.z-this->B.z)*ray.direction.y-(this->A.y-this->B.y)*ray.direction.z))+
				 (ray.direction.x*((this->A.y-this->B.y)*(this->A.z-ray.origin.z)-(this->A.z-this->B.z)*(this->A.y-ray.origin.y))))/A;


	double t=(((this->A.x-this->B.x)*((this->A.y-this->C.y)*(this->A.z-ray.origin.z)-(this->A.z-this->C.z)*(this->A.y-ray.origin.y)))+
			 ((this->A.x-this->C.x)*((this->A.z-this->B.z)*(this->A.y-ray.origin.y)-(this->A.y-this->B.y)*(this->A.z-ray.origin.z)))+
			 ((this->A.x-ray.origin.x)*((this->A.y-this->B.y)*(this->A.z-this->C.z)-(this->A.z-this->B.z)*(this->A.y-this->C.y))))/A;


	if(t <= EPS)    return Vector(INFP);
    Vector ip = Vector(ray.origin + ray.direction*t);
	return ip;

}

Vector Checkerboard::getColor(Vector p){

    Vector ref = this->A + (-this->X-this->Y)*INF;
	long long int i=(long long int) (  projectedLength(p-ref,this->X ) / this->blocksize );
	long long int j=(long long int) (  projectedLength(p-ref,this->Y ) / this->blocksize );
    //printf("ref: %lld %lld\n", i, j );
	if( (i^j)&1 )   return this->color1*255;
	return this->color2*255;
}

void Checkerboard::glDraw(){
    int i,j,N = 100;
    int bs = this->blocksize;
    Vector ref = this->A + (-this->X)*bs*(N/2) + (-this->Y)*bs*(N/2);

    glPushMatrix();

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                Vector col = ( (i^j)&1 )?this->color1:this->color2;
                glColor3f( CO( Vector(col) ) );
                glBegin(GL_QUADS);
                    glVertex3f( CO( Vector( ref + this->X*(i*bs) + this->Y*(j*bs) ) ) );		    // lower left
                    glVertex3f( CO( Vector( ref + this->X*((i+1)*bs) + this->Y*(j*bs) ) ) );		// lower right
                    glVertex3f( CO( Vector( ref + this->X*((i+1)*bs) + this->Y*((j+1)*bs) ) ) );	// upper right
                    glVertex3f( CO( Vector( ref + this->X*(i*bs) + this->Y*((j+1)*bs) ) ) );		// upper left
                glEnd();
            }
        }

    glPopMatrix();
}
