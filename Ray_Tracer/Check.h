#ifndef __CHECK_IS_INCLUDED__
#define __CHECK_IS_INCLUDED__

#include "MyMath.h"
#include "Vector.h"
#include "Object.h"
#include "Square.h"

class Check : public Square{

public:
    double size;
	int N;
	Vector color1;
	Vector color2;

	Check();
	Check(Vector ll, Vector x, Vector y, double size, int n);

	void setColor1(Vector col);
	void setColor2(Vector col);

    Vector getColor(Vector p);
    void glDraw();
};

#endif

