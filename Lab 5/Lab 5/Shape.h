#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <GL/glut.h>
#include <SOIL2.h>
#include <stdlib.h>
#include <vector>
#include <random>
using namespace std;
#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
protected:
	int numSurface;
	// connecting points
	vector<vector<float>>p;
public:
	Shape();
	Shape(int numSurface);
	virtual void loadTexture(const char* textureName[]);
	virtual void draw();
	virtual void drawMesh();
	int getNumSurface();
	int getVectorPointSize();
	~Shape() 
	{ 
		p.clear(); 
	};
};
#endif