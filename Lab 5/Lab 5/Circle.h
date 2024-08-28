#include "Shape.h"
using namespace std;
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
class Circle :public Shape
{
private:
	float r;
	GLuint textureList[1];
public:
	Circle();
	Circle(int numSurface, float r);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Circle() {};
};
#endif