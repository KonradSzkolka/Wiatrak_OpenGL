#include <GL/glut.h>
#include "init.h"
#include "app_state.h"

void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    GLfloat globalAmbient[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    // LIGHT0 - mocna zarowka z gory
    GLfloat light0Ambient[] = { 0.14f, 0.14f, 0.12f, 1.0f };
    GLfloat light0Diffuse[] = { 1.00f, 0.96f, 0.88f, 1.0f };
    GLfloat light0Specular[] = { 0.95f, 0.92f, 0.85f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.65f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.008f);

    // LIGHT1 - cieple swiatlo z okna, przytlumione zaslona
    GLfloat light1Ambient[] = { 0.11f, 0.08f, 0.04f, 1.0f };
    GLfloat light1Diffuse[] = { 0.95f, 0.76f, 0.42f, 1.0f };
    GLfloat light1Specular[] = { 0.30f, 0.22f, 0.10f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0f);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0f);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.85f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.012f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.001f);
}

void init()
{
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    initLighting();
}

void setLights()
{
    // LIGHT0 - mocna zarowka z gory
    GLfloat light0Pos[] = { 0.0f, 4.3f, 0.0f, 1.0f };

    // LIGHT1 - bardzo blisko okna, przy lewej scianie
    GLfloat light1Pos[] = { -5.0f, 1.45f, 1.10f, 1.0f };

    // kierunek bardziej do srodka sceny i lekko na stol,
    // a mniej na prawa sciane
    GLfloat light1Dir[] = { 0.05f, -0.10f, -0.10f };

    if (gState.light0Enabled)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);

    if (gState.light1Enabled)
        glEnable(GL_LIGHT1);
    else
        glDisable(GL_LIGHT1);

    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1Dir);
}