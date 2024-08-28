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
#ifndef _REGULARPOLYGON_H_
#define _REGULARPOLYGON_H_
class RegularPolygon :public Shape
{
private:
	float x, y, n, r;
public:
	RegularPolygon();
	RegularPolygon(float param, float x, float y, float n, float r);
	void drawRegularPolygonOpenGL(int x, int y, int n, int r);
	void draw();
	~RegularPolygon() {};
};
#endif
