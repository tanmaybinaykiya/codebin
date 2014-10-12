#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include "Colors.h"
#include "RayTracer.h"
#include "bitmap_image.hpp"


RayTracer::RayTracer(){

}


RayTracer::RayTracer(World w, double pd, int md){
	this->world = w;
	this->proDist = pd;
	this->maxDepth = md;
}

void RayTracer::setDimension(int w, int h){
    this->proWidth = w;
    this->proHeight = h;
}

void RayTracer::setWorld(World w){
    this->world = w;
}

bool comp(std::pair<int, double> a, std::pair<int, double> b){
	return a.second < b.second;
}


Vector RayTracer::refract(Object* obj, Ray ray){
    Vector p = obj->intersect(ray);
    Vector N = obj->getNormal(p);
    double dot = DOT(N, ray.direction);

    double n1 = this->world.RI;
    double n2 = obj->RI;

    if(dot > 0){
        N = -N;
        n1 = (n1+n2) - (n2=n1);
    }
    double th1 = acos( DOT(-N, ray.direction) );
    double th2 = asin( n1 * sin(th1) / n2 );
    double del = th1-th2;

    return rotateVector(ray.direction, CROSS(ray.direction, -N), del );
}

Vector RayTracer::traceRay(Ray ray, int depth, bool shadow){

    int i;
    std::vector< std::pair<int, double> > dists;
    Object* obj;

    for(i=0;i<this->world.nObj;i++){
        obj = this->world.getObject(i);
        Vector ip = obj->intersect(ray);

        dists.push_back( std::make_pair(i, (ip-ray.origin).mag() ) );
    }

    for(i=0;i<this->world.nL;i++){
        obj = this->world.getLightSource(i);
        Vector ip = obj->intersect(ray);

        //ip = Vector(INFP);

        dists.push_back( std::make_pair(this->world.nObj+i, (ip-ray.origin).mag() ) );
    }

    sort(dists.begin(), dists.end(), comp);

    bool light=false;
    if( light = (dists[0].first >= this->world.nObj) )  obj = this->world.getLightSource(dists[0].first-this->world.nObj);
    else                                                obj = this->world.getObject(dists[0].first);

    Vector p = obj->intersect(ray);

    //if(light) printf("got light!\n");

    if(shadow){
        if(light){

            return ((LightSource*)obj)->intensity * obj->getColor(p);
        }else{
            Vector rd = refract(obj, ray);

            Ray forwardRay(p+rd*1, rd);
            Vector transCol = this->traceRay(forwardRay, depth+1, false);
            return obj->T *  transCol;
        }
    }

    if( p == Vector(INFP) )   return Vector(BLACK);

    //Vector final_color = obj->getColor(p);
    Vector final_color = this->world.ambient * obj->getColor(p);

    if(light)  return rgbnorm(obj->getColor(p) * ((LightSource*)obj)->intensity );     //for light source


    Vector reflectedColor = Vector(BLACK);
    Vector transCol = Vector(BLACK);
    if(depth < this->maxDepth){
        Ray reflectedray( p, obj->reflect(p, ray) );

        if(obj->T < 1.){
            reflectedColor = this->traceRay(reflectedray, depth+1, false);
        }

        if(obj->T > 0.){

            Vector rd = refract(obj, ray);

            Ray forwardRay(p+rd*EPS*2, rd);
            transCol = this->traceRay(forwardRay, depth+1, false);

            final_color = final_color + (1-obj->S) * obj->T * transCol;
        }
    }


    for(i=0;i<this->world.nL;i++){

        Vector lightDir = (this->world.getLightSource(i) )->O - p;
        lightDir.norm();
        Ray shadowRay(p, lightDir);

        Vector N = obj->getNormal(p);
        double dot = DOT( N, lightDir);

        if(dot > 0){
            Vector shadowCol = this->traceRay(shadowRay, depth+1, true);
            final_color = final_color +   (1-obj->T) * (1-obj->S) * dot * ( MULT(obj->getColor(p), shadowCol) );
        }
        final_color = final_color + (1-obj->T) * ( obj->S * reflectedColor ) ;
    }

    return rgbnorm(final_color);
}

void RayTracer::trace(std::string title){

    bitmap_image image(this->proWidth, this->proHeight);

    int i, j;
    Vector ref = (this->world.camera.front * this->proDist) + (-this->world.camera.right)*(this->proWidth-1)/2 + this->world.camera.up*(this->proHeight-1)/2;
    for(i=0;i<this->proHeight;i++){
        for(j=0;j<this->proWidth;j++){
            Vector p = ref - this->world.camera.up*i + this->world.camera.right*j;
            p = (p-this->world.camera.position);
            p.norm();

            Ray R(this->world.camera.position, p);

            Vector col = this->traceRay(R, 0, false);

            image.set_pixel(j, i, CO(col));

        }
    }

    image.save_image(title.c_str());
}

