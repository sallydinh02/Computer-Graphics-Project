#include "Shape.h"
using namespace std;
#ifndef _PARABOLOID_H_
#define _PARABOLOID_H_
class Paraboloid :public Shape
{
private:
	float r;
	
public:
	GLuint textureList[1];
	Paraboloid();
	Paraboloid(int numSurface, float r);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Paraboloid() {};
};
#endif