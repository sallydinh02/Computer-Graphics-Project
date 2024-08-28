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
#ifndef _SQUARE_H_
#define _SQUARE_H_
class Square :public Shape
{
private:
	float x, y, w;
public:
	Square();
	Square(float param, float x, float y, float w);
	void drawSquareOpenGL(int x, int y, int w);
	void draw();
	~Square() {};
};
#endif
