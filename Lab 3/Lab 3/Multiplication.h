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
#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_
class Multiplication :public Shape
{
private:
	float x, y, a, b;
public:
	Multiplication();
	Multiplication(float param, float x, float y, float a, float b);
	void drawMultiplicationOpenGL(int x, int y, int a, int b);
	void draw();
	~Multiplication() {};
};
#endif
