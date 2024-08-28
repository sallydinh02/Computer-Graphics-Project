#include "Shape.h"
using namespace std;
#ifndef _CYLINDER_H_
#define _CYLINDER_H_
class Cylinder :public Shape
{
private:
	float r, h;
	GLuint textureList[3];
public:
	Cylinder();
	Cylinder(int numSurface, float r, float h);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Cylinder() {};
};
#endif
