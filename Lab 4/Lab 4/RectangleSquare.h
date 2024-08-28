#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include <chrono>
#include <stdlib.h>
#include "Point.h"
using namespace std;
using namespace std::chrono;
#ifndef _RECTANGLESQUARE_H_
#define _RECTANGLESQUARE_H_
class RectangleSquare :public Shape
{
private:
	//Point a, b, c, d;
	//a is top left
	//c is bottom right
	float xa, ya, xb, yb, xc, yc, xd, yd;
	float xmid, ymid;
public:
	RectangleSquare();
	RectangleSquare(int numVertice, float xa, float ya, float xb, float yb);
	void draw();
	void setMid(float x, float y);
	float getXMid();
	float getYMid();
	~RectangleSquare() {};
};
#endif
