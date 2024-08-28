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
#ifndef _HYPERBOLA_H_
#define _HYPERBOLA_H_
class Hyperbola :public Shape
{
private:
	float xc, yc, major, minor;
public:
	Hyperbola();
	Hyperbola(float param, float xc, float yc, float major, float minor);
	void MidPoint(float xc, float yc, float a, float b);
	void putPixel(float x, float y);
	void draw();
	void drawHyperbolaOpenGL(float xc, float yc, float major, float minor);
	~Hyperbola() {};
};
#endif