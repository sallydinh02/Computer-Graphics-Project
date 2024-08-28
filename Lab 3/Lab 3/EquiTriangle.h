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
#ifndef _EQUITRIANGLE_H_
#define _EQUITRIANGLE_H_
class EquiTriangle :public Shape
{
private:
	float x, y, height, length;
public:
	EquiTriangle();
	EquiTriangle(float param, float x, float y, float height, float length);
	void drawEquiTriangleOpenGL(int x, int y, int height, int length);
	void draw();
	~EquiTriangle() {};
};
#endif
