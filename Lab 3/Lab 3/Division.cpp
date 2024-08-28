#include "Division.h"

Division::Division()
{
	this->x = 0;
	this->y = 0;
	this->a = 50;
	this->b = 50;
}

Division::Division(float param, float x, float y, float a, float b) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

void Division::drawDivisionOpenGL(int x, int y, int a, int b)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x+a, y);
	glVertex2i(x-a/2, y+b);
	glVertex2i(x-a/2-a, y+b);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Division::draw()
{
	drawDivisionOpenGL(this->x, this->y, this->a, this->b);
}