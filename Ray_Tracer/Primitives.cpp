//#include "mygl.h"
#include "MyMath.h"
#include "Colors.h"
#include "Vector.h"
#include "Primitives.h"


Box::Box(double l, double w, double h, Vector col=Vector(WHITE)){
	this->length = l;
	this->width = w;
	this->height = h;

	this->colTop = new Vector(CO(col));
	this->colBottom = new Vector(CO(col));
	this->colSideA1 = new Vector(CO(col));
	this->colSideA2 = new Vector(CO(col));
	this->colSideB1 = new Vector(CO(col));
	this->colSideB2 = new Vector(CO(col));
}

Box::~Box(){
	delete this->colTop;
	delete this->colBottom;
	delete this->colSideA1;
	delete this->colSideA2;
	delete this->colSideB1;
	delete this->colSideB2;
}

void Box::setColTop(double r, double g, double b){
	this->colTop->x = r;
	this->colTop->y = g;
	this->colTop->z = b;
}

void Box::setColBottom(double r, double g, double b){
	this->colBottom->x = r;
	this->colBottom->y = g;
	this->colBottom->z = b;
}

void Box::setColSideA1(double r, double g, double b){
	this->colSideA1->x = r;
	this->colSideA1->y = g;
	this->colSideA1->z = b;
}
void Box::setColSideA2(double r, double g, double b){
	this->colSideA2->x = r;
	this->colSideA2->y = g;
	this->colSideA2->z = b;
}

void Box::setColSideB1(double r, double g, double b){
	this->colSideB1->x = r;
	this->colSideB1->y = g;
	this->colSideB1->z = b;
}

void Box::setColSideB2(double r, double g, double b){
	this->colSideB2->x = r;
	this->colSideB2->y = g;
	this->colSideB2->z = b;
}

void Box::DrawBox(){

	Vector a = I*length;
	Vector b = J*width;
	Vector c = K*height;


	//draw bottom
	glColor3f(CO(Vector(*(this->colBottom))));
	glBegin(GL_QUADS);{
		glVertex3f(CO(origin));
		glVertex3f(CO(a));
		glVertex3f(CO(Vector(a+b)));
		glVertex3f(CO(b));
	}glEnd();

	//draw top
	glPushMatrix();{
		glTranslatef(CO(c));
		glColor3f(CO(Vector(*(this->colTop))));
		glBegin(GL_QUADS);{
			glVertex3f(CO(origin));
			glVertex3f(CO(a));
			glVertex3f(CO(Vector(a+b)));
			glVertex3f(CO(b));
		}glEnd();
	}glPopMatrix();

	//draw the sideA1
	glColor3f(CO(Vector(*this->colSideA1)));
	glBegin(GL_QUADS);{
		glVertex3f(CO(origin));
		glVertex3f(CO(a));
		glVertex3f(CO(Vector(a+c)));
		glVertex3f(CO(c));
	}glEnd();

	//draw the sideA2
	glPushMatrix();{
		glTranslatef(CO(b));
		glColor3f(CO(Vector(*(this->colSideA2))));
		glBegin(GL_QUADS);{
			glVertex3f(CO(origin));
			glVertex3f(CO(a));
			glVertex3f(CO(Vector(a+c)));
			glVertex3f(CO(c));
		}glEnd();
	}glPopMatrix();

	//draw the sideB1
	glColor3f(CO(Vector(*(this->colSideB1))));
	glBegin(GL_QUADS);{
		glVertex3f(CO(origin));
		glVertex3f(CO(c));
		glVertex3f(CO(Vector(b+c)));
		glVertex3f(CO(b));
	}glEnd();

	//draw the sideB2
	glPushMatrix();{
		glTranslatef(CO(a));
		glColor3f(CO(Vector(*(this->colSideB2))));
		glBegin(GL_QUADS);{
			glVertex3f(CO(origin));
			glVertex3f(CO(c));
			glVertex3f(CO(Vector(b+c)));
			glVertex3f(CO(b));
		}glEnd();
	}glPopMatrix();

}


//draws a plygon with n vertices and of radius r
void DrawPolygon(int n, double r, Vector color){
	glPushMatrix();{

		glColor3f(CO(color));

		glBegin(GL_TRIANGLE_FAN);{
			glVertex3f(CO(origin));
			for(int i=0;i<=n;i++){
				glVertex3f(CO(Vector(r*cos(2./n * i * PI), r*sin(2./n * i * PI), 0)));
			}
		}glEnd();

	}glPopMatrix();
}


//draws a filled Cylinder with n vertices, radious r and height h
void DrawFilledCylinder(GLUquadricObj* quadric, int n, double r, double h, Vector colSurface, Vector colSides){

	glPushMatrix();{

		DrawPolygon(n, r, colSurface);
		glColor3f(CO(colSides));
		gluCylinder(quadric, r, r, h, n, 30);

		glTranslatef(CO( Vector( K*h) ) );
		DrawPolygon(n, r, colSurface);

	}glPopMatrix();

}
