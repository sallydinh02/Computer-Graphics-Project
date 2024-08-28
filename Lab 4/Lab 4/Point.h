#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <GL/glut.h>
#include <stdlib.h>
using namespace std;
#ifndef _POINT_H_
#define _POINT_H_
class Point
{
private: 
	float x, y;
public:
	Point();
	Point(float x, float y);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	~Point() {};
};
#endif