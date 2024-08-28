#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include <chrono>
#include <stdlib.h>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
using namespace std::chrono;
#ifndef _DIVISION2_H_
#define _DIVISION2_H_
class NewDivision :public Shape
{
private:
	float x, y, r, w, h;
public:
	NewDivision();
	NewDivision(float param, float x, float y, float r, float w, float h);
	void drawNewDivisionOpenGL(int x, int y, int r, int w, int h);
	void draw();
	~NewDivision() {};
};
#endif