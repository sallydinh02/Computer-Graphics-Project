#include "Shape.h"
#include "Shape.h"
Shape::Shape()
{
	this->numSurface = -1;
}
Shape::Shape(int numSurface)
{
	this->numSurface = numSurface;
}


void Shape::loadTexture(const char* textureName[])
{
	
}

void Shape::draw()
{

};

void Shape::drawMesh()
{

};

int Shape::getNumSurface()
{
	return this->numSurface;
}

int Shape::getVectorPointSize()
{
	return this->p.size();
}