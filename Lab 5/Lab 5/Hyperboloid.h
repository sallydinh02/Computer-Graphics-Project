#include "Shape.h"
using namespace std;
#ifndef _HYPERBOLOID_H_
#define _HYPERBOLOID_H_
class Hyperboloid :public Shape
{
private:
	float depth, a, b, c;

public:
	GLuint textureList[3];
	Hyperboloid();
	Hyperboloid(int numSurface, float a, float b, float c, float depth);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Hyperboloid() {};
};
#endif