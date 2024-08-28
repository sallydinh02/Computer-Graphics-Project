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
#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_
class Ellipse :public Shape
{
private:
	float xc, yc, a, b;
public:
	Ellipse();
	Ellipse(float param, float xc, float yc, float a, float b);
	void MidPoint(int xc, int yc, int a, int b);
	void drawEllipseOpenGL(int xc, int yc, int a, int b);
	void draw();
	void putPixel(int x, int y);
	~Ellipse() {};
};
#endif