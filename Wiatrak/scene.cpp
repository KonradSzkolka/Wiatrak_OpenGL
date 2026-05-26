#include <cmath>
#include <GL/glut.h>
#include "scene.h"
#include "init.h"
#include "app_state.h"
#include "animation.h"

void drawWindow()
{
    glPushMatrix();
    glColor3f(0.9f, 0.88f, 0.82f);
    glTranslatef(-4.45f, 0.2f, 0.0f);
    glScalef(0.08f, 5.0f, 6.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.75f, 0.75f, 0.78f);
    glTranslatef(-4.3f, 0.25f, 0.0f);
    glScalef(0.06f, 3.0f, 3.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.65f, 0.82f, 0.92f);
    glTranslatef(-4.22f, 0.25f, 0.0f);
    glScalef(0.03f, 2.5f, 3.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.72f);
    glTranslatef(-4.2f, 0.25f, 0.0f);
    glScalef(0.04f, 2.5f, 0.08f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawCurtain()
{
    float strength = getCurtainStrength();

    glPushMatrix();
    glColor3f(0.35f, 0.25f, 0.15f);
    glTranslatef(-4.2f, 1.9f, -0.6f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4f, 0.08f, 0.08f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor3f(0.82f, 0.82f, 0.9f);

    for (int i = 0; i < 16; i++)
    {
        float z = -1.7f + i * 0.18f;

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= 16; j++)
        {
            float y = 1.8f - j * 0.22f;
            float localPhase = gState.curtainTime * 2.2f + i * 0.35f + j * 0.18f;
            float wave = sin(localPhase) * strength * 2.0f * (j / 16.0f);

            glNormal3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(-4.15f + wave, y, z);
            glVertex3f(-4.15f + wave, y, z + 0.16f);
        }
        glEnd();
    }
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
    const float bladeX[10] = { 0.05f, 0.20f, 0.55f, 1.00f, 1.28f, 1.38f, 1.28f, 1.00f, 0.55f, 0.20f };
    const float bladeY[10] = { 0.00f, 0.10f, 0.16f, 0.12f, 0.05f, 0.00f, -0.05f, -0.12f, -0.16f, -0.10f };

    glPushMatrix();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    for (int i = 0; i < 10; i++)
        glVertex3f(bladeX[i], bladeY[i], 0.03f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, -1.0f);
    for (int i = 9; i >= 0; i--)
        glVertex3f(bladeX[i], bladeY[i], -0.03f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 10; i++)
    {
        int a = i % 10;
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(bladeX[a], bladeY[a], 0.03f);
        glVertex3f(bladeX[a], bladeY[a], -0.03f);
    }
    glEnd();

    glPopMatrix();
}

void drawBlades()
{
    glPushMatrix();
    glRotatef(gState.bladeAngle, 0.0f, 0.0f, 1.0f);

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

void drawGuardWireDisk(float z)
{
    for (float r = 0.45f; r <= 1.40f; r += 0.22f)
    {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++)
        {
            float angle = 2.0f * 3.1415926f * i / 100.0f;
            float x = r * cos(angle);
            float y = r * sin(angle);
            glVertex3f(x, y, z);
        }
        glEnd();
    }

    glBegin(GL_LINES);
    for (int i = 0; i < 24; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 24.0f;
        float x = 1.40f * cos(angle);
        float y = 1.40f * sin(angle);

        glVertex3f(0.0f, 0.0f, z);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void drawGuard()
{
    glColor3f(0.88f, 0.88f, 0.9f);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.22f);
    glutSolidTorus(0.04f, 1.42f, 20, 80);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.22f);
    glutSolidTorus(0.04f, 1.42f, 20, 80);
    glPopMatrix();

    glPushMatrix();
    glutSolidTorus(0.025f, 1.18f, 16, 70);
    glPopMatrix();

    glDisable(GL_LIGHTING);
    drawGuardWireDisk(0.18f);
    drawGuardWireDisk(-0.18f);

    glBegin(GL_LINES);
    for (int i = 0; i < 16; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 16.0f;
        float x = 1.42f * cos(angle);
        float y = 1.42f * sin(angle);

        glVertex3f(x, y, -0.22f);
        glVertex3f(x, y, 0.22f);
    }
    glEnd();

    glEnable(GL_LIGHTING);
}

void drawHead()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.15f, 0.0f);
    glRotatef(gState.headAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(gState.tiltAngle, 1.0f, 0.0f, 0.0f);

    drawMotorBody();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.55f);
    drawBlades();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.55f);
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

void drawTable()
{
    glPushMatrix();
    glColor3f(0.45f, 0.28f, 0.16f);
    glTranslatef(0.0f, -2.35f, 0.0f);
    glScalef(8.0f, 0.18f, 5.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32f, 0.20f, 0.12f);
    glTranslatef(-3.2f, -3.5f, 1.8f);
    glScalef(0.22f, 2.2f, 0.22f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32f, 0.20f, 0.12f);
    glTranslatef(3.2f, -3.5f, 1.8f);
    glScalef(0.22f, 2.2f, 0.22f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32f, 0.20f, 0.12f);
    glTranslatef(-3.2f, -3.5f, -1.8f);
    glScalef(0.22f, 2.2f, 0.22f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32f, 0.20f, 0.12f);
    glTranslatef(3.2f, -3.5f, -1.8f);
    glScalef(0.22f, 2.2f, 0.22f);
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

    drawWindow();
    drawCurtain();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -3.0f);

    drawTable();
    drawBase();
    drawStand();
    drawHead();

    glPopMatrix();

    glutSwapBuffers();
}
