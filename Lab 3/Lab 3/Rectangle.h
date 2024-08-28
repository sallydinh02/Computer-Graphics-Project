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
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
class Rectangle :public Shape
{
private:
	float x, y, w, h;
public:
	Rectangle();
	Rectangle(float param, float x, float y, float w, float h);
	void drawRectangleOpenGL(int x, int y, int w, int h);
	void draw();
	~Rectangle() {};
};
#endif
