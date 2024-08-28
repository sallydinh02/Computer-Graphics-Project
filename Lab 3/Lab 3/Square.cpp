#include "Square.h"
Square::Square()
{
	this->x = 0;
	this->y = 0;
	this->w = 50;
}

Square::Square(float param, float x, float y, float w) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->w = w;
}

void Square::drawSquareOpenGL(int x, int y, int w)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + w);
	glVertex2i(x + w, y + w);
	glVertex2i(x + w, y);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Square::draw()
{
	drawSquareOpenGL(this->x, this->y, this->w);
}