#include "Shape.h"
Shape::Shape()
{
	this->param = -1;
}
Shape::Shape(float param)
{
	this->param = param;
}
float Shape::getParam()
{
    return this->param;
}
void Shape::draw() 
{  
};