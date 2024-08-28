#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <GL/glut.h>
#include <stdlib.h>
using namespace std;
#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
private:
	float param;
public:
	Shape();
	Shape(float param);
	virtual void draw();
	float getParam();
	~Shape() {};
};
#endif