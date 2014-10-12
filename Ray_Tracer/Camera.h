#ifndef __CAMERA_IS_INCLUDED__
#define __CAMERA_IS_INCLUDED__

struct Camera{
public:
    Vector front;
    Vector up;
    Vector right;
    Vector position;
    Camera();
    Camera(Vector F, Vector U, Vector R);
    Camera(Vector F, Vector U, Vector R, Vector pos);
    Vector LookAtPosition();
    void Move(Vector dir, double value);
    void Pitch(double angle);
    void Turn(double angle);
    void Roll(double angle);
};

#endif
