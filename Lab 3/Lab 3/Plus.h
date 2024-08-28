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
#ifndef _PLUS_H_
#define _PLUS_H_
class Plus :public Shape
{
private:
	float x, y, a, b;
public:
	Plus();
	Plus(float param, float x, float y, float a, float b);
	void drawPlusOpenGL(int x, int y, int a, int b);
	void draw();
	~Plus() {};
};
#endif
