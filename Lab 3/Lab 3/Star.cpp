#include "Star.h"
GLfloat Pi = 3.1415926536f;

int numEdge = 5;
//int e = 50;

Star::Star()
{
	this->x = 0;
	this->y = 0;
	this->e = 10;
}

Star::Star(float param, float x, float y, float e) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->e = e;
}

void Star::drawStarOpenGL(int x, int y, int e)
{
	GLfloat pi = 3.1415926f;
	float centralAngle = (2 * pi) / numEdge;
	float R = e * sqrt(1.0 / (2 * (1 - cos(centralAngle))));
	float theta = pi / 2 - centralAngle / 2;

	float r = (R - e * cos(3 * pi / 10))/cos(pi / 5);
	float smallTheta = pi / 2;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 5; i++)
	{
		glVertex2f(x + R * cos(theta), y + R * sin(theta));
		//glVertex2f(x + r * cos(smallTheta), y + r * sin(smallTheta));
		theta += centralAngle;
		smallTheta += centralAngle;
	}

	glEnd();
	glFlush();

}

void Star::draw()
{
	drawStarOpenGL(this->x, this->y, this->e);
}