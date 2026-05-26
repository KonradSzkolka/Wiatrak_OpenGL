#pragma once
#include <GL/glut.h>

extern GLuint gFloorTexture;
extern GLuint gWallTexture;

bool loadTextures();
GLuint loadTexture(const char* path);