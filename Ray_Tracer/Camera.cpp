#include<math.h>
#include "Vector.h"
#include "Camera.h"
#include "stdio.h"

Camera::Camera(){

}

Camera::Camera(Vector F,Vector U,Vector R){
	this->front = F;
	this->up = U;
	this->right = R;
}

Camera::Camera(Vector F,Vector U,Vector R, Vector pos){
	this->front = F;
	this->up = U;
	this->right = R;
	this->position = pos;
}

Vector Camera::LookAtPosition(){
	return (this->position + this->front * 30);
}

//move forward or backward with magnitude 'value'
void Camera::Move(Vector dir, double value)
{
	this->position = this->position + dir * value;
}

//pitch up or down 'angle' degrees
void Camera::Pitch(double angle)
{
	double rad = angle*2*acos(0.)/180;
	Vector up1 = this->up*cos(rad)+ this->front*sin(rad);
	Vector front1 = this->front*cos(rad)+ (-this->up)*sin(rad);
	this->up = up1;
	this->front = front1;
}

//turn left or right 'angle' degrees
void Camera::Turn(double angle)
{
	double rad = angle*2*acos(0.)/180;
	Vector front1 = this->front*cos(rad)+ this->right*sin(rad);
	Vector right1 = this->right*cos(rad)+ (-this->front)*sin(rad);
	this->front = front1;
	this->right = right1;
}

//roll left or right 'angle' degrees
void Camera::Roll(double angle)
{
	double rad = angle*2*acos(0.)/180;
	Vector up1 = this->up*cos(rad)+ this->right*sin(rad);
	Vector right1 = this->right*cos(rad)+ (-this->up)*sin(rad);
	this->up = up1;
	this->right = right1;
}
