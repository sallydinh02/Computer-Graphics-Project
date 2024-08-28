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
#ifndef _ARROW_H_
#define _ARROW_H_
class Arrow :public Shape
{
private:
	float x, y, w, h, e, ht;
public:
	Arrow();
	Arrow(float param, float x, float y, float w, float h, float e, float ht);
	void drawArrowOpenGL(int x, int y, int w, int h, int e, int ht);
	void draw();
	~Arrow() {};
};
#endif
