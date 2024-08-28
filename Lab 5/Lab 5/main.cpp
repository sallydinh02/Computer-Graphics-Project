#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include "Shape.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Circle.h"
#include "Ring.h"
#include "Paraboloid.h"
#include "Hyperboloid.h"
using namespace std;

#define PI 3.1415926535898
/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
/*  D degrees of rotation */
#define DEF_D 5

/*  Globals */
int th = 0;   /* azimuth of view angle */
int ph = 0;   /* elevation of view angle */
double dim = 2.0; /* dimension of orthogonal box */
bool toggleMode = true;

/* Global variables */
char title[] = "20125060_Lab4";
int refreshMills = 5; // refresh interval in miliseconds [new]
const char* textureName[6] = { "texture/ice2.jpg", "texture/fur.jpg", "texture/colorflow3.jpg", "texture/leaf2.jpg",
"texture/peach2.jpg", "texture/wood2.jpg"};
Shape* shape1 = new Cube(6);
float rSphere = 1;
float rCylinder = 0.6;
float height = 1.8;
float yrot = 0.0f;
float inner_r = 0.21f;
float outer_r = 1.0f;
float rPara = 1.2f;
Shape* shape2 = new Sphere(1, rSphere);
Shape* shape3 = new Cylinder(3, rCylinder, height);
Shape* shape4 = new Cone(2, rCylinder, height);
Shape* shape5 = new Circle(1, rSphere);
Shape* shape6 = new Ring(1, inner_r, outer_r);
Shape* shape7 = new Hyperboloid(3, 0.5, 0.5, 0.5, 1);
Shape* shape8 = new Paraboloid(1, rPara);

void setEye()
{
	if (toggleMode) 
	{
		double Ex = -2 * dim * Sin(th) * Cos(ph);
		double Ey = +2 * dim * Sin(ph);
		double Ez = +2 * dim * Cos(th) * Cos(ph);
		/* camera/eye position, aim of camera lens, up-vector */
		gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, Cos(ph), 0);
	}
	/*  Orthogonal - set world orientation */
	else 
	{
		glRotatef(ph, 1, 0, 0);
		glRotatef(th, 0, 1, 0);
	}
}

// load bitmaps and convert to textures [new]
void loadGLTextures()
{
	shape1->loadTexture(textureName);
	shape2->loadTexture(textureName);
	shape3->loadTexture(textureName);
	shape4->loadTexture(textureName);
	shape5->loadTexture(textureName);
	shape6->loadTexture(textureName);
	shape7->loadTexture(textureName);
	shape8->loadTexture(textureName);
	//cout << "Load textures in main" << endl;
}

// Do all the drawing here [new]
void display(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth
	glMatrixMode(GL_MODELVIEW);
	//glOrtho(0.0f, 1400, 1400, 0.0f, 0.0f, 1.0f);
	/* Cube */
	// Cube mesh
	glLoadIdentity();
	glTranslatef(-3.0f, 2.0f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape1->drawMesh();

	// 3d Cube
	glLoadIdentity(); // Reset The View
	glTranslatef(-3.0f, -1.5f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape1->draw();

	/* Sphere */

	// Sphere mesh

	glLoadIdentity();
	glTranslatef(0.0f, 2.0f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape2->drawMesh();

	// 3D Sphere
	glLoadIdentity(); // Reset The View
	glTranslatef(0.0f, -1.5f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape2->draw();

	/* Cylinder */

	// Cylinder mesh

	glLoadIdentity();
	glTranslatef(3.0f, 2.0f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape3->drawMesh();

	// 3D Cylinder
	glLoadIdentity(); // Reset The View
	glTranslatef(3.0f, -1.5f, -7.0f);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape3->draw();

	/* Cone */

	// Cone mesh
	glLoadIdentity();
	glTranslatef(6.0f, 2.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape4->drawMesh();

	// 3D Cone
	glLoadIdentity(); // Reset The View
	glTranslatef(6.0f, -1.5f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape4->draw();

	/* Circle */
	// Circle mesh
	glLoadIdentity();
	glTranslatef(-4.0f, 1.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	//glRotatef(-15, 0, 1, 0);
	shape5->drawMesh();

	// rotated circle
	glLoadIdentity(); // Reset The View
	glTranslatef(-4.0f, -2.5f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 1.0f);
	shape5->draw();

	/* Ring (torus) */
	// Ring mesh
	glLoadIdentity();
	glTranslatef(-0.5f, 0.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape6->drawMesh();

	// 3D Ring
	glLoadIdentity(); // Reset The View
	glTranslatef(-0.5f, -3.2f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape6->draw();

	/* Hyperboloid */
	// Hyperboloid mesh
	glLoadIdentity();
	glTranslatef(3.2f, 0.5f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape7->drawMesh();

	// 3D Hyperboloid
	// Reset The View
	glLoadIdentity(); 
	//glTranslatef(0.0f, 0.0f, -7.0f);
	glTranslatef(3.2f, -3.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape7->draw();

	/* Paraboloid */
	// Paraboloid mesh
	glLoadIdentity();
	glTranslatef(6.0f, 1.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape8->drawMesh();

	// 3D Paraboloid
	glLoadIdentity(); // Reset The View
	glTranslatef(6.0f, -2.5f, -7.0f);
	//glTranslatef(0.0f, 0.0f, -7.0f);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(yrot, 0.0f, 2.0f, 0.0f);
	shape8->draw();

	glutSwapBuffers();
	yrot -= 0.15f;
	//cout << "Display" << endl;
}


/* Initialize OpenGL Graphics */
void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f); // Set background depth to farthest
	glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL); // Set the type of depth-test
	glShadeModel(GL_SMOOTH); // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
	loadGLTextures();
	//drawGLScene();
	//cout << "Init GL" << endl;
}

// call back when timer expired [new]
void timer(int value)
{
	// Post re-paint request to activate display()
	glutPostRedisplay();
	// next timer call milliseconds later
	glutTimerFunc(refreshMills, timer, 0);
	//cout << "Timer" << endl;
}

/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) 
{ // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1; // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);
	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
	glLoadIdentity(); // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	//gluLookAt(0.0, 0.0, 0.0, 0.0, -100, 0.0, 0.0, 1.0, 0.0);
	gluPerspective(60.0f, aspect, 0.3f, 100.0f);
	//cout << "Reshape" << endl;
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480); // Set the window's initial width & height
	glutInitWindowPosition(10, 10); // Position the window's initial top-left corner
	glutCreateWindow(title); // Create window with the given title
	initGL();
	//loadGLTextures();
	glutDisplayFunc(display); // Register callback handler for window re-paint event
	glutReshapeFunc(reshape); // Register callback handler for window re-size event
	// Our own OpenGL initialization
	glutTimerFunc(0, timer, 0);
	glutMainLoop(); // Enter the infinite event-processing loop
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;
	delete shape5;
	delete shape6;
	delete shape7;
	delete shape8;
	return 0;
}