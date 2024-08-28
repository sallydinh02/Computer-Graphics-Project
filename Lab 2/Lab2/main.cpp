#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Hyperbola.h"
#include "Parabola.h"
#include "Ellipse.h"
#include <vector>
using namespace std;

vector<float> v;
bool flag = true;
int counter = 0;

void drawShape(void)
{
    /*glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();*/
    if (v[0] == 0 || v[0]==1)
    {
        Shape* shape=new Line(v[0], v[1], v[2], v[3], v[4]);
        shape->draw();
        delete(shape);
    }
    else if (v[5] == 2)
    {
        Shape* shape = new Circle(v[6], v[7], v[8], v[9]);
        shape->draw();
        delete(shape);
    }
    else if (v[10] == 3)
    {
        Shape* shape = new Ellipse(v[11], v[12], v[13], v[14], v[15]);
        shape->draw();
        delete(shape);
    }
    else if (v[16] == 4)
    {
        Shape* shape = new Parabola(v[17], v[18], v[19], v[20]);
        shape->draw();
        delete(shape);
    }
    else if (v[21]==5)
    {
        Shape* shape = new Hyperbola(v[22], v[23], v[24], v[25], v[26]);
        shape->draw();
        delete(shape);
    }
}

void reshape(int w, int h)
{
    glDepthMask(GL_TRUE); // insert this line
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_CULL_FACE);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
    glMatrixMode(GL_MODELVIEW);
    glutSwapBuffers();

}

void mouse(int button, int state,
    int mousex, int mousey)
{
    // Check if the current click
    // is left-click or not
    if (button == GLUT_RIGHT_BUTTON
        && state == GLUT_DOWN) {
        if (counter > 5) {
            counter = 0;
        }

        else counter++;
        cout << "Click count: " << counter << endl;

        // Redisplay
        glutReshapeFunc(reshape);
    }
}

void init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
    glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char** argv) {

    ifstream fin;
    fin.open("Input.txt");
    string line;
    float n;
    

    if (!fin.is_open()) cout << "Can't open file" << endl;
    else
    {
        while (getline(fin, line, '\n'))
        {
            while (fin >> n)
            {
                v.push_back(n);
            }
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutInitWindowSize(800, 800);
            glutInitWindowPosition(0, 0);
            glutCreateWindow("20125060_Lab1");
            init();
            glutDisplayFunc(drawShape);
            /*glutReshapeFunc(reshape);*/
            glutMouseFunc(mouse);
            glutMainLoop();
            v.clear();
        }
    }
    fin.close();

    return 0;
    //slope>1
    /*v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(800);
    v.push_back(820);*/

    //slope=1
    /*v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(800);
    v.push_back(800);*/

    //slope=-1
   /* v.push_back(1);
    v.push_back(1);
    v.push_back(800);
    v.push_back(800);
    v.push_back(1);*/

    //slope<1
    /*v.push_back(1);
    v.push_back(1);
    v.push_back(700);
    v.push_back(800);
    v.push_back(600);*/

    //horizonal
    /*v.push_back(1);
    v.push_back(10);
    v.push_back(200);
    v.push_back(800);
    v.push_back(820);*/

    //vertical
    /*v.push_back(0);
    v.push_back(50);
    v.push_back(200);
    v.push_back(50);
    v.push_back(820);*/

    /*v.push_back(2);
    v.push_back(400);
    v.push_back(400);
    v.push_back(350);*/

    /*v.push_back(3);
    v.push_back(400);
    v.push_back(400);
    v.push_back(300);
    v.push_back(150);*/

    /*v.push_back(4);
    v.push_back(80);
    v.push_back(50);
    v.push_back(1);*/

    /*v.push_back(5);
    v.push_back(280);
    v.push_back(210);
    v.push_back(50);
    v.push_back(40);*/

    /*glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Draw");
    init();
    glutDisplayFunc(drawShape);*/

    //glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    
    //glutMainLoop();
    //v.clear();
}