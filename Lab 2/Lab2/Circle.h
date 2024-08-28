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
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
class Circle :public Shape
{
private:
	float xc, yc, r;
public:
	Circle();
	Circle(float param, float xc, float yc, float r);
	void MidPoint(int xc, int yc, int r);
	void drawCircleOpenGL(int xc, int yc, int r);
	void draw();
	void putPixel(int x, int y);
	~Circle() {};
};
#endif
