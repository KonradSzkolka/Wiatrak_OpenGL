#include <iostream>
#include <GL/glut.h>
#include "init.h"
#include "scene.h"
#include "animation.h"
#include "input.h"
#include "textures.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Wiatrak 3D");

    init();

    if (!loadTextures())
    {
        std::cout << "Blad ladowania tekstur!" << std::endl;
    }

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}