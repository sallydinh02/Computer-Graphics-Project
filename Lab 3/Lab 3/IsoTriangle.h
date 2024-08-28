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
#ifndef _ISOTRIANGLE_H_
#define _ISOTRIANGLE_H_
class IsoTriangle :public Shape
{
private:
	float x, y, length;
public:
	IsoTriangle();
	IsoTriangle(float param, float x, float y, float length);
	void drawIsoTriangleOpenGL(int x, int y, int length);
	void draw();
	~IsoTriangle() {};
};
#endif
