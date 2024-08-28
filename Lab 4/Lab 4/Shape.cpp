#include "Shape.h"
Shape::Shape()
{
	this->numVertice = -1;
	//p = NULL;
}
Shape::Shape(int numVertice)
{
	this->numVertice = numVertice;
	/*p = new float* [this->numVertice];
	for (int i = 0; i < this->numVertice; i++)
		p[i] = new float[2];*/
}
int Shape::getNumVertice()
{
	return this->numVertice;
}
void Shape::draw()
{
};

float Shape::getXMid()
{
	return 1;
}

float Shape::getYMid()
{
	return 1;
}

void Shape::setMid(float x, float y)
{

}

int Shape::getVectorPointSize()
{
	return this->p.size();
}

//void Shape::drawAnyPolygon(float arrX[50], float arrY[50], int idx)
//{
	//this->numVertice++;
	//if (rightClick)
	//{
	//	//cout << "Num vertice: " << this->numVertice << endl;
	//	cout << "\n Inside class, right click, vector" << endl;
	//	glBegin(GL_LINE_STRIP);
	//	cout << p[this->p.size() - 3][0] << " " << p[this->p.size() - 3][1] << endl;
	//	cout << p[this->p.size() - 2][0]<<" " << p[this->p.size() - 2][1]<< endl;
	//	cout << p[this->p.size() - 1][0]<<" " << p[this->p.size() - 1][1]<< endl;
	//	glVertex2f(p[this->p.size() - 3][0], p[this->p.size() - 3][1]);
	//	glVertex2f(p[this->p.size() - 2][0], p[this->p.size() - 2][1]);
	//	glVertex2f(p[this->p.size() - 1][0], p[this->p.size() - 1][1]);
	//	glEnd();
	//	glFlush();
	//}
	//else
	//{
	//	vector<float>tmp = { arrX[idx], arrY[idx] };
	//	this->p.push_back(tmp);
	//	cout << "Vector size: " << this->p.size() << endl;
	//	glBegin(GL_LINE_STRIP);
	//	for (int k = 0; k < this->p.size(); k++)
	//	{
	//		cout << "\n Inside class, left click, vector" << endl;
	//		cout << p[k][0] << " " << p[k][1] << endl;
	//		glVertex2f(p[k][0], p[k][1]);
	//	}
	//	glEnd();
	//	glFlush();
	//}
//}