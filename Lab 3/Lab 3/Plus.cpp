#include "Plus.h"

Plus::Plus()
{
	this->x = 0;
	this->y = 0;
	this->a = 50;
	this->b = 50;
}

Plus::Plus(float param, float x, float y, float a, float b) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

void Plus::drawPlusOpenGL(int x, int y, int a, int b)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + a);
	glVertex2i(x-a, y + a);
	glVertex2i(x-a, y + a+b);
	glVertex2i(x, y + a+b);
	glVertex2i(x, y + 2*a+b);
	glVertex2i(x+b, y + 2*a+b);
	glVertex2i(x+b, y + a+b);
	glVertex2i(x+a+b, y + a+b);
	glVertex2i(x+a+b, y + a);
	glVertex2i(x+b, y + a);
	glVertex2i(x+b, y);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Plus::draw()
{
	drawPlusOpenGL(this->x, this->y, this->a, this->b);
}