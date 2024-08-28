#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include <chrono>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;
#ifndef _PARABOLA_H_
#define _PARABOLA_H_
class Parabola :public Shape
{
private:
	float xc, yc, p;
public:
	Parabola();
	Parabola(float param, float xc, float yc, float p);
	void MidPoint(float xc, float yc, float p);
	void putPixel(float x, float y);
	void draw();
	void drawParabolaOpenGL(float xc, float yc, float p);
	~Parabola() {};
};
#endif
