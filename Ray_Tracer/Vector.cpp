#include<math.h>
#include "Vector.h"

#define EPS 1e-10

// +0.00000000aders01

#define S(x)	((x)*(x))
#define Z(x)	(fabs(x) < EPS)
#define MAX(a,b) (((a)>(b))?(a):(b))

Vector::Vector(){

}

Vector::Vector(double x,double y,double z){
	this->x=x;
	this->y=y;
	this->z=z;
}

bool Vector::isZero(){
    return Z(x) && Z(y) && Z(z);
}
double Vector::mag(){
    return sqrt(mag2());
}
double Vector::mag2(){
    return S(x)+S(y)+S(z);
}
void Vector::norm(){ //make this unit
    double m = mag();
    x/=m;
    y/=m;
    z/=m;

    if(x < EPS && x > -EPS) x = 0.;
    if(y < EPS && y > -EPS) y = 0.;
    if(z < EPS && z > -EPS) z = 0.;
}
Vector Vector::unit(){	//this unchanged, make a unit copy of this
    Vector u(x,y,z);
    u.norm();
    return u;
}


Vector operator+(Vector a,Vector b){
	return Vector(a.x+b.x, a.y+b.y, a.z+b.z);	}

Vector operator-(Vector a){
	return Vector(-a.x, -a.y, -a.z);	}

Vector operator-(Vector a,Vector b){
	return Vector(a.x-b.x, a.y-b.y, a.z-b.z);	}

Vector operator*(Vector a,Vector b){
	return CROSS(a,b);	}

Vector operator*(Vector a, double b){		// A*2.
	return Vector(a.x*b, a.y*b, a.z*b);	}

Vector operator*(double b, Vector a){		// 2.*A
	return Vector(a.x*b, a.y*b, a.z*b);	}

Vector operator/(Vector a, double b){		// A/2.
	return Vector(a.x/b, a.y/b, a.z/b);	}

bool operator==(Vector a, Vector b){		// A/2.
	return (fabs(a.x-b.x) <= 1e-4 && fabs(a.x-b.x) <= 1e-4 && fabs(a.x-b.x) <= 1e-4);	}



double DOT(Vector a, Vector b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector MULT(Vector a, Vector b){
	return rgbnorm(Vector(a.x*b.x, a.y*b.y, a.z*b.z));
}

Vector CROSS(Vector a, Vector b){
	Vector c;
	c.x = a.y*b.z - a.z*b.y;
	c.y = a.z*b.x - a.x*b.z;
	c.z = a.x*b.y - a.y*b.x;
	return c;
}



//length of a on b
double projectedLength(Vector a, Vector b){
	return DOT(a, b.unit());
}

//vector component of a on b
Vector projectedVector(Vector a, Vector b){
//	return b.unit() * projectedLength(a,b);
	Vector ub = b.unit();
	return ub * DOT(a, ub);
}

//rotatee=a, axis=s, angle=alpha
Vector rotateVector(Vector a, Vector s, double alpha){	//
	Vector us = s.unit();
	Vector ap = projectedVector(a, us);	//a_parallel
	Vector al = a - ap;					//a_lombo
	Vector b  = us * al;

	//rotated( a_lombo ), X=al, Y=b
	Vector ral = al*cos(alpha) + b*sin(alpha);

	return ap + ral;
}

Vector rgbnorm(Vector a){
    double max = MAX( MAX( a.x, a.y ), a.z );
    if(max <= 255) return a;
    Vector n = a/max;
    n = n*255.;
    return n;
}

