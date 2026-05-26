#include <GL/glut.h>
#include "init.h"

void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    GLfloat light0Diff[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light1Diff[] = { 0.5f, 0.5f, 0.8f, 1.0f };

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diff);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diff);
}

void init()
{
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    initLighting();
}

void setLights()
{
    GLfloat light0Pos[] = { 4.0f, 5.0f, 4.0f, 1.0f };
    GLfloat light1Pos[] = { -4.0f, 3.0f, 2.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
}