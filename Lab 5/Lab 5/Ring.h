#include "Shape.h"
using namespace std;
#ifndef _RING_H_
#define _RING_H_
class Ring :public Shape
{
private:
	float r, R;
	GLuint textureList[1];
public:
	Ring();
	Ring(int numSurface, float r, float R);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Ring() {};
};
#endif
