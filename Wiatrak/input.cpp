#include <cstdlib>
#include <GL/glut.h>
#include "input.h"
#include "app_state.h"

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '0':
        gState.fanSpeedLevel = 0;
        break;
    case '1':
        gState.fanSpeedLevel = 1;
        break;
    case '2':
        gState.fanSpeedLevel = 2;
        break;
    case '3':
        gState.fanSpeedLevel = 3;
        break;
    case 'o':
    case 'O':
        gState.oscillationOn = !gState.oscillationOn;
        break;
    }

    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        if (gState.tiltAngle > -20.0f)
            gState.tiltAngle -= 2.0f;
        break;

    case GLUT_KEY_DOWN:
        if (gState.tiltAngle < 0.0f)
            gState.tiltAngle += 2.0f;
        break;
    }

    glutPostRedisplay();
}