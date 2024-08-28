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
#ifndef _NPOLYGON_H_
#define _NPOLYGON_H_
class NPolygon :public Shape
{
private:
	float xmid, ymid;
public:
	NPolygon();
	//numVertice=idx+1
	NPolygon(int numVertice, float arrX[50], float arrY[50]);
	void draw();
	float getXMid();
	float getYMid();
	void setMid(float x, float y);
	void calculateCentroid();
	~NPolygon() {};
};
#endif
