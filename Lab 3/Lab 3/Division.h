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
#ifndef _DIVISION_H_
#define _DIVISION_H_
class Division :public Shape
{
private:
	float x, y, a, b;
public:
	Division();
	Division(float param, float x, float y, float a, float b);
	void drawDivisionOpenGL(int x, int y, int a, int b);
	void draw();
	~Division() {};
};
#endif
