#include "Shape.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
#ifndef _SPHERE_H_
#define _SPHERE_H_
class Sphere :public Shape
{
private:
	float r;
	GLuint textureList[6];
public:
	Sphere();
	Sphere(int numSurface, float r);
	void loadTexture(const char* textureName[]);
	void draw();
	void drawMesh();
	~Sphere() {};
};
#endif
