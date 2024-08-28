#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include <chrono>
#include <stdlib.h>
#include <GL/glut.h>
using namespace std;
using namespace std::chrono;
#ifndef _STAR_H_
#define _STAR_H_
class Star :public Shape
{
private:
	float x, y, e;
public:
	Star();
	Star(float param, float x, float y, float e);
	void drawStarOpenGL(int x, int y, int e);
	void draw();
	~Star() {};
};
#endif
