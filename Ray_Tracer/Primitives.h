#ifndef __BOX__
#define __BOX__

#include "Vector.h"
#include "mygl.h"

extern Vector origin, I, J, K;

class Box{
public:
	double length, width, height;
	Vector *colTop, *colBottom;
	Vector *colSideA1, *colSideA2;
	Vector *colSideB1, *colSideB2;
	
	Box(){};
	Box(double, double, double, Vector);
	~Box();
	
	void DrawBox();
	void setColTop(double, double, double);
	void setColBottom(double, double, double);
	void setColSideA1(double, double, double);
	void setColSideA2(double, double, double);
	void setColSideB1(double, double, double);
	void setColSideB2(double, double, double);
};


void DrawPolygon(int n, double r, Vector color);
void DrawFilledCylinder(GLUquadricObj*, int n, double r, double h, Vector colSurface, Vector colSides);

#endif
