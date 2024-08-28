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
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
class Triangle :public Shape
{
private:
	float xa, ya, xb, yb, xc, yc;
	float xmid, ymid;
public:
	Triangle();
	Triangle(int numVertice, float xa, float ya, float xb, float yb);
	void draw();
	void setMid(float x, float y);
	float getXMid();
	float getYMid();
	~Triangle() {};
};
#endif
