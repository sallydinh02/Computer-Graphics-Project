#include "Rectangle.h"
Rectangle::Rectangle()
{
	this->x = 0;
	this->y = 0;
	this->w = 50;
	this->h = 50;
}

Rectangle::Rectangle(float param, float x, float y, float w, float h) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Rectangle::drawRectangleOpenGL(int x, int y, int w, int h)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y+h);
	glVertex2i(x+w, y+h);
	glVertex2i(x+w, y);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Rectangle::draw()
{
	drawRectangleOpenGL(this->x, this->y, this->w, this->h);
}