#include "IsoTriangle.h"
IsoTriangle::IsoTriangle()
{
	this->x = 0;
	this->y = 0;
	this->length = 50;
}

IsoTriangle::IsoTriangle(float param, float x, float y, float length):Shape(param)
{
	this->x = x;
	this->y = y;
	this->length = length;
}

void IsoTriangle::drawIsoTriangleOpenGL(int x, int y, int length)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y-length);
	glVertex2i(x+length, y);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void IsoTriangle::draw()
{
	drawIsoTriangleOpenGL(this->x, this->y, this->length);
}