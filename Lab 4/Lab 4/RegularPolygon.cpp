#include "RegularPolygon.h"

RegularPolygon::RegularPolygon()
{
	this->xmid = 0;
	this->ymid = 0;
	this->r = 0;
}

RegularPolygon::RegularPolygon(int numVertice, float xa, float ya, float xb, float yb) :Shape(numVertice)
{
	this->xmid = xa + (xb - xa) / 2;
	this->ymid = ya + (yb - ya) / 2;
	cout << "Old mid: " << this->xmid << " " << this->ymid << endl;
	this->r = (yb - ya) / 2;

	//pentagon will not upright
	//float angleIncrement = 360.0f / getNumVertice();
	//GLfloat pi = 3.1415926f;
	//angleIncrement *= pi / 180.0f;
	////glBegin(GL_LINE_LOOP);
	//float angle = 0.0f;
	//cout << "Regular polygon: n = " << getNumVertice() << endl;
	//for (int i = 0; i < getNumVertice(); i++)
	//{
	//	p[i][0] = this->xmid + this->r * cos(angle);
	//	p[i][1] = this->ymid + this->r * sin(angle);
	//	cout << p[i][0] << " " << p[i][1] << endl;
	//	//glVertex2f(p[i][0], p[i][1]);
	//	angle += angleIncrement;
	//}

	//all regular polygons will be upright
	GLfloat pi = 3.1415926f;
	float centralAngle = (2 * pi) / getNumVertice();
	float R = this->r * sqrt(1.0 / (2 * (1 - cos(centralAngle))));
	float theta = pi / 2 - centralAngle / 2;
	cout << "Regular polygon: n = " << getNumVertice() << endl;
	//vector<float>tmp;
	for (int i = 0; i < getNumVertice(); i++)
	{
		/*p[i][0] = this->xmid + R * cos(theta);
		p[i][1] = this->ymid + R * sin(theta);
		cout << p[i][0] << " " << p[i][1] << endl;
		theta += centralAngle;*/
		/*tmp.push_back(this->xmid + R * cos(theta));
		tmp.push_back(this->ymid + R * sin(theta));*/
		p.push_back({ this->xmid + R * cos(theta), this->ymid + R * sin(theta) });
		cout << p[i][0] << " " << p[i][1] << endl;
		theta += centralAngle;
	}
}

void RegularPolygon::setMid(float x, float y)
{
	this->xmid += x;
	this->ymid += y;
}

float RegularPolygon::getXMid()
{
	return xmid;
}

float RegularPolygon::getYMid()
{
	return ymid;
}

void RegularPolygon::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->getNumVertice(); i++)
	{
		glVertex2f(p[i][0], p[i][1]);
	}
	glEnd();
	glFlush();
}