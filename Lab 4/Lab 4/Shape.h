#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <GL/glut.h>
#include <stdlib.h>
#include "Point.h"
#include <vector>
using namespace std;
#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
private:
	int numVertice;
public:
	//float** p;
	vector<vector<float>>p;
	Shape();
	Shape(int numVertice);
	virtual void draw();
	//void drawAnyPolygon(float arrX[50], float arrY[50], int idx);
	int getNumVertice();
	int getVectorPointSize();
	virtual float getXMid();
	virtual float getYMid();
	virtual void setMid(float x, float y);
	~Shape() { p.clear(); };
};
#endif