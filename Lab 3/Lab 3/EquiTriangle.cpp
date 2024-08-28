#include "EquiTriangle.h"
EquiTriangle::EquiTriangle()
{
	this->x = 0;
	this->y = 0;
	this->height = 50;
	this->length = 50;
}

EquiTriangle::EquiTriangle(float param, float x, float y, float height, float length) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->length = length;
}

void EquiTriangle::drawEquiTriangleOpenGL(int x, int y, int height, int length)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x - length / 2, y + height);
	glVertex2i(x + length / 2, y + height);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void EquiTriangle::draw()
{
	drawEquiTriangleOpenGL(this->x, this->y, this->height, this->length);
}