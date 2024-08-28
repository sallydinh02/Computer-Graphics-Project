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
#ifndef _LINE_H_
#define _LINE_H_
class Line :public Shape
{
private:
	float x1, y1, x2, y2;
public:
	Line();
	Line(float param, float x1, float y1, float x2, float y2);
	void draw();
	void drawLineOpenGL(int x1, int y1, int x2, int y2);
	~Line() {};
};
#endif
