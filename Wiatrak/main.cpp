#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

float bladeAngle = 0.0f;
int fanSpeedLevel = 0; // 0,1,2,3
bool oscillationOn = true;
float headAngle = 0.0f;
float headDirection = 1.0f;

float getBladeSpeed()
{
    switch (fanSpeedLevel)
    {
    case 1: return 4.0f;
    case 2: return 10.0f;
    case 3: return 20.0f;
    default: return 0.0f;
    }
}

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

void drawWireCircle(float radius)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 100.0f;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void drawBase()
{
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.23f);
    glTranslatef(0.0f, -2.1f, 0.0f);
    glScalef(3.0f, 0.25f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.15f, 0.15f, 0.18f);
    glTranslatef(0.0f, -1.95f, 0.0f);
    glScalef(1.4f, 0.08f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawStand()
{
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.63f);
    glTranslatef(0.0f, -1.1f, 0.0f);
    glScalef(0.22f, 1.8f, 0.22f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4f, 0.4f, 0.45f);
    glTranslatef(0.0f, -0.15f, 0.0f);
    glutSolidSphere(0.18f, 24, 24);
    glPopMatrix();
}

void drawMotorBody()
{
    glPushMatrix();
    glColor3f(0.75f, 0.75f, 0.78f);
    glScalef(1.0f, 0.9f, 1.2f);
    glutSolidSphere(0.45f, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.35f);
    glTranslatef(0.0f, 0.0f, -0.45f);
    glScalef(0.5f, 0.5f, 0.8f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawBlade()
{
    glPushMatrix();
    glTranslatef(0.75f, 0.0f, 0.0f);
    glScalef(1.5f, 0.22f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawBlades()
{
    glPushMatrix();
    glRotatef(bladeAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.15f, 0.55f, 0.85f);

    for (int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f);
        drawBlade();
        glPopMatrix();
    }

    glColor3f(0.9f, 0.75f, 0.15f);
    glutSolidSphere(0.12f, 20, 20);

    glPopMatrix();
}

void drawGuard()
{
    glDisable(GL_LIGHTING);
    glColor3f(0.85f, 0.85f, 0.85f);

    for (float r = 0.5f; r <= 1.5f; r += 0.25f)
        drawWireCircle(r);

    glBegin(GL_LINES);
    for (int i = 0; i < 16; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 16.0f;
        float x = 1.5f * cos(angle);
        float y = 1.5f * sin(angle);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    glEnable(GL_LIGHTING);
}

void drawHead()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.15f, 0.0f);
    glRotatef(headAngle, 0.0f, 1.0f, 0.0f);

    drawMotorBody();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.55f);
    drawBlades();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.7f);
    drawGuard();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.35f);
    glScalef(0.12f, 0.12f, 0.5f);
    glColor3f(0.7f, 0.7f, 0.72f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}

void drawFloor()
{
    glPushMatrix();
    glColor3f(0.35f, 0.2f, 0.1f);
    glTranslatef(0.0f, -2.3f, 0.0f);
    glScalef(8.0f, 0.08f, 5.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1000.0 / 700.0, 1.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.5, 3.0, 8.5, 0.0, -0.2, 0.0, 0.0, 1.0, 0.0);

    setLights();

    drawFloor();
    drawBase();
    drawStand();
    drawHead();

    glutSwapBuffers();
}

void update()
{
    bladeAngle += getBladeSpeed();
    if (bladeAngle >= 360.0f)
        bladeAngle -= 360.0f;

    if (oscillationOn)
    {
        headAngle += 0.18f * headDirection;

        if (headAngle >= 35.0f)
        {
            headAngle = 35.0f;
            headDirection = -1.0f;
        }
        else if (headAngle <= -35.0f)
        {
            headAngle = -35.0f;
            headDirection = 1.0f;
        }
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '0':
        fanSpeedLevel = 0;
        break;
    case '1':
        fanSpeedLevel = 1;
        break;
    case '2':
        fanSpeedLevel = 2;
        break;
    case '3':
        fanSpeedLevel = 3;
        break;
    case 'o':
    case 'O':
        oscillationOn = !oscillationOn;
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Wiatrak 3D");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}