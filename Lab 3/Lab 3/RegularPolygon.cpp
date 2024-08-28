#include "RegularPolygon.h"
RegularPolygon::RegularPolygon()
{
	this->x = 0;
	this->y = 0;
	this->n = 5;
	this->r = 50;
}

RegularPolygon::RegularPolygon(float param, float x, float y, float n, float r):Shape(param)
{
	this->x = x;
	this->y = y;
	this->n = n;
	this->r = r;
}

void RegularPolygon::drawRegularPolygonOpenGL(int x, int y, int n, int r)
{
	float angleIncrement = 360.0f / n;  
	GLfloat pi = 3.1415926f;
	angleIncrement *= pi / 180.0f;    
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	float angle = 0.0f;
	for (int i = 0; i < n; i++) 
	{
		glVertex2i(x+r * cos(angle), y+r * sin(angle));
		angle += angleIncrement;
	}
	glEnd();
	glFlush();
}

void RegularPolygon::draw()
{
	drawRegularPolygonOpenGL(this->x, this->y, this->n, this->r);
}