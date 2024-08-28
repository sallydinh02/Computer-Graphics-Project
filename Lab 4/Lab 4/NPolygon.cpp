#include "NPolygon.h"

NPolygon::NPolygon()
{
	this->xmid = 0;
	this->ymid = 0;
	//this->r = 0;
}

void NPolygon::calculateCentroid()
{
	float doubleA = 0;
	float sumX = 0;
	float sumY = 0;
	for (int i = 0; i < this->getNumVertice() - 1; i++)
	{
		doubleA += ((this->p[i][0]*this->p[i+1][1]) - (this->p[i+1][0] * this->p[i][1]));
		sumX += ((this->p[i][0] + this->p[i + 1][0]) * ((this->p[i][0] * this->p[i + 1][1]) - (this->p[i + 1][0] * this->p[i][1])));
		sumY += ((this->p[i][1] + this->p[i + 1][1]) * ((this->p[i][0] * this->p[i + 1][1]) - (this->p[i + 1][0] * this->p[i][1])));
	}
	/*cout << "xmid: " << xmid << endl;
	cout << "ymid: " << ymid << endl;*/
	doubleA+= ((this->p[0][0] * this->p[1][1]) - (this->p[1][0] * this->p[0][1]));
	sumX += ((this->p[0][0] + this->p[1][0]) * ((this->p[0][0] * this->p[1][1]) - (this->p[1][0] * this->p[0][1])));
	sumY += ((this->p[0][1] + this->p[1][1]) * ((this->p[0][0] * this->p[1][1]) - (this->p[1][0] * this->p[0][1])));
	cout << "A: " << doubleA / 2 << endl;
	cout << "sumX: " << sumX << endl;
	cout << "sumY: " << sumY << endl;
	this->xmid = 1 / (6 * doubleA / 2) * sumX;
	this->ymid = 1 / (6 * doubleA / 2) * sumY;

	cout << "xmid: " << xmid << endl;
	cout << "ymid: " << ymid << endl;
}

NPolygon::NPolygon(int numVertice, float arrX[50], float arrY[50]) :Shape(numVertice)
{
	/*this->xmid = xa + (xb - xa) / 2;
	this->ymid = ya + (yb - ya) / 2;
	cout << "Old mid: " << this->xmid << " " << this->ymid << endl;
	this->r = (yb - ya) / 2;*/

	
	
	cout << "N-polygon: n = " << getNumVertice() << endl;
	//vector<float>tmp;
	
	for (int i = 0; i < getNumVertice(); i++)
	{
		/*p[i][0] = this->xmid + R * cos(theta);
		p[i][1] = this->ymid + R * sin(theta);
		cout << p[i][0] << " " << p[i][1] << endl;
		theta += centralAngle;*/
		/*tmp.push_back(this->xmid + R * cos(theta));
		tmp.push_back(this->ymid + R * sin(theta));*/
		p.push_back({ arrX[i], arrY[i] });
	}
	calculateCentroid();
}

void NPolygon::setMid(float x, float y)
{
	this->xmid += x;
	this->ymid += y;
}

float NPolygon::getXMid()
{
	return xmid;
}

float NPolygon::getYMid()
{
	return ymid;
}

void NPolygon::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->getNumVertice(); i++)
	{
		glVertex2f(p[i][0], p[i][1]);
	}
	glEnd();
	glFlush();
}