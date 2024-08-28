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
	float xmid, ymid, r;
public:
	RegularPolygon();
	RegularPolygon(int numVertice, float xa, float ya, float xb, float yb);
	void draw();
	float getXMid();
	float getYMid();
	void setMid(float x, float y);
	~RegularPolygon() {};
};
#endif
