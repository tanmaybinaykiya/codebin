#include "mygl.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include "Triangle.h"


Triangle::Triangle()
{

}

Triangle::Triangle(Vector A,Vector B,Vector C)
{
	this->A=A;
	this->B=B;
	this->C=C;

	//printf("triangle (%.2lf,%.2lf,%.2lf)  (%.2lf,%.2lf,%.2lf)  (%.2lf,%.2lf,%.2lf)\n",CO(A), CO(B), CO(C) );
}


Vector Triangle::getNormal(Vector point)
{
    Vector PA = (this->A-point);
    Vector PB = (this->B-point);
    Vector PC = (this->C-point);

    Vector N = CROSS(PB,PC);
    Vector N1 = CROSS(PA,PB);

    Vector t=CROSS(N,N1);
    //assert(fabs(t.mag()) <= EPS);

    N.norm();



	return N;
}


Vector Triangle::reflect(Vector point, Ray ray)
{
    Vector I = ray.direction;
    Vector N = this->getNormal(point);

    if(DOT(N, I) > 0)   N =-N;

    Vector R = I - 2*DOT(N, I)*N;
    R.norm();

    //assert(DOT(N, R) > 0);
    return R;
}

Vector Triangle::intersect(Ray ray)
{
    /*
    Vector    u, v, n;             // triangle vectors
    Vector    dir, w0, w;          // ray vectors
    float     r, a, b;             // params to calc ray-plane intersect

    // get triangle edge vectors and plane normal
    u = this->B - this->A;
    v = this->C - this->A;
    n = CROSS(u, v);             // cross product
    if ( fabs(n.mag()-0) <= EPS )            // triangle is degenerate
        return Vector(INFP);                 // do not deal with this case

    dir = ray.direction;             // ray direction vector
    w0 = (ray.origin+ray.direction) - this->A;
    a = -DOT(n,w0);
    b = DOT(n,dir);
    if (fabs(b) < EPS) {     // ray is parallel to triangle plane
        return Vector(INFP);             // ray disjoint from plane
    }

    // get intersect point of ray with triangle plane
    r = a / b;
    if (r < 0.0)                   // ray goes away from triangle
        return Vector(INFP);                  // => no intersect
    // for a segment, also test if (r > 1.0) => no intersect

    Vector IP = ray.origin + r * dir;

    // is I inside T?
    float    uu, uv, vv, wu, wv, D;
    uu = DOT(u,u);
    uv = DOT(u,v);
    vv = DOT(v,v);
    w = IP - this->A;
    wu = DOT(w,u);
    wv = DOT(w,v);
    D = uv * uv - uu * vv;

    // get and test parametric coords
    float s, t;
    s = (uv * wv - vv * wu) / D;
    if (s < 0.0 || s > 1.0)        // I is outside T
        return Vector(INFP);
    t = (uv * wu - uu * wv) / D;
    if (t < 0.0 || (s + t) > 1.0)  // I is outside T
        return Vector(INFP);
    printf("triangle intersect\n");
    return IP;                      // I is in T
*/


	double A=(((this->A.x-this->B.x)*((this->A.y-this->C.y)*ray.direction.z-(this->A.z-this->C.z)*ray.direction.y))+
			 ((this->A.x-this->C.x)*((this->A.z-this->B.z)*ray.direction.y-(this->A.y-this->B.y)*ray.direction.z))+
			 (ray.direction.x*((this->A.y-this->B.y)*(this->A.z-this->C.z)-(this->A.z-this->B.z)*(this->A.y-this->C.y))));
    //printf("triangle intersect A: %g\n",A);


	double beta=(((this->A.x-ray.origin.x)*((this->A.y-this->C.y)*ray.direction.z-(this->A.z-this->C.z)*ray.direction.y))+
			 ((this->A.x-this->C.x)*((this->A.z-ray.origin.z)*ray.direction.y-(this->A.y-ray.origin.y)*ray.direction.z))+
			 (ray.direction.x*((this->A.y-ray.origin.y)*(this->A.z-this->C.z)-(this->A.z-ray.origin.z)*(this->A.y-this->C.y))))/A;

	double gamma=(((this->A.x-this->B.x)*((this->A.y-ray.origin.y)*ray.direction.z-(this->A.z-ray.origin.z)*ray.direction.y))+
				 ((this->A.x-ray.origin.x)*((this->A.z-this->B.z)*ray.direction.y-(this->A.y-this->B.y)*ray.direction.z))+
				 (ray.direction.x*((this->A.y-this->B.y)*(this->A.z-ray.origin.z)-(this->A.z-this->B.z)*(this->A.y-ray.origin.y))))/A;


	double t=(((this->A.x-this->B.x)*((this->A.y-this->C.y)*(this->A.z-ray.origin.z)-(this->A.z-this->C.z)*(this->A.y-ray.origin.y)))+
			 ((this->A.x-this->C.x)*((this->A.z-this->B.z)*(this->A.y-ray.origin.y)-(this->A.y-this->B.y)*(this->A.z-ray.origin.z)))+
			 ((this->A.x-ray.origin.x)*((this->A.y-this->B.y)*(this->A.z-this->C.z)-(this->A.z-this->B.z)*(this->A.y-this->C.y))))/A;


	if(beta+gamma>1 || beta<=0 || gamma<=0)
	{
		return Vector(INFP);
	}

    //printf("triangle intersect %g\n",t);
	if(t <= EPS)    return Vector(INFP);
    Vector ip = Vector(ray.origin + ray.direction*t);
	return ip;

}

Vector Triangle::getColor(Vector p){
    //printf("triangle color\n");
    return this->color*255;
}

void Triangle::glDraw(){
    glPushMatrix();
        glColor3f( CO(this->color) );
        glBegin(GL_TRIANGLES);		// Drawing Using Triangles
            glVertex3f( CO(A) );		// Top
            glVertex3f( CO(B) );		// Bottom Left
            glVertex3f( CO(C) );		// Bottom Right
        glEnd();
    glPopMatrix();
}
