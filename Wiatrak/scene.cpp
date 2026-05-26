#include <cmath>
#include <GL/glut.h>
#include "scene.h"
#include "init.h"
#include "app_state.h"
#include "animation.h"
#include "textures.h"

void setMetalMaterial()
{
    GLfloat ambient[] = { 0.20f, 0.20f, 0.22f, 1.0f };
    GLfloat diffuse[] = { 0.55f, 0.57f, 0.60f, 1.0f };
    GLfloat specular[] = { 0.85f, 0.85f, 0.88f, 1.0f };
    GLfloat shininess = 80.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glColor3f(0.60f, 0.62f, 0.66f);
}

void setBladeMaterial()
{
    GLfloat ambient[] = { 0.08f, 0.20f, 0.30f, 1.0f };
    GLfloat diffuse[] = { 0.15f, 0.55f, 0.85f, 1.0f };
    GLfloat specular[] = { 0.25f, 0.25f, 0.28f, 1.0f };
    GLfloat shininess = 25.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glColor3f(0.15f, 0.55f, 0.85f);
}

void setHubMaterial()
{
    GLfloat ambient[] = { 0.25f, 0.20f, 0.05f, 1.0f };
    GLfloat diffuse[] = { 0.90f, 0.75f, 0.15f, 1.0f };
    GLfloat specular[] = { 0.55f, 0.45f, 0.12f, 1.0f };
    GLfloat shininess = 45.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glColor3f(0.90f, 0.75f, 0.15f);
}

void drawWindow()
{
    glPushMatrix();
    glColor3f(0.55f, 0.36f, 0.22f);
    glTranslatef(-4.38f, 0.25f, 0.0f);
    glScalef(0.045f, 3.35f, 3.95f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.45f, 0.28f, 0.16f);
    glTranslatef(-4.30f, 0.25f, 0.0f);
    glScalef(0.06f, 3.0f, 3.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.72f, 0.86f, 0.92f);
    glTranslatef(-4.22f, 0.25f, 0.0f);
    glScalef(0.03f, 2.5f, 3.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.40f, 0.25f, 0.15f);
    glTranslatef(-4.20f, 0.25f, 0.0f);
    glScalef(0.04f, 2.5f, 0.08f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawCurtain()
{
    float strength = getCurtainStrength();

    // karnisz
    glPushMatrix();
    glColor3f(0.50f, 0.32f, 0.20f);
    glTranslatef(-4.22f, 1.9f, -0.20f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.55f, 0.08f, 0.08f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // zas³ona - jeden materia³, trochê spokojniejsza fala
    glColor3f(0.93f, 0.72f, 0.80f);

    int segmentsZ = 18;
    int segmentsY = 16;

    for (int i = 0; i < segmentsZ; i++)
    {
        float z0 = -1.92f + i * 0.19f;
        float z1 = z0 + 0.19f;

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= segmentsY; j++)
        {
            float t = j / (float)segmentsY;
            float y = 1.8f - t * 3.5f;

            float localPhase = gState.curtainTime * 2.2f + i * 0.35f + j * 0.18f;
            float wave = sinf(localPhase) * strength * 0.25f * t; // du¿o mniejsza amplituda

            float x = -4.18f + wave;

            glNormal3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(x, y, z0);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }
}

void drawBase()
{
    setMetalMaterial();

    glPushMatrix();
    glTranslatef(0.0f, -2.1f, 0.0f);
    glScalef(3.0f, 0.25f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.95f, 0.0f);
    glScalef(1.4f, 0.08f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawStand()
{
    setMetalMaterial();

    glPushMatrix();
    glTranslatef(0.0f, -1.1f, 0.0f);
    glScalef(0.22f, 1.8f, 0.22f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.15f, 0.0f);
    glutSolidSphere(0.18f, 24, 24);
    glPopMatrix();
}

void drawMotorBody()
{
    setMetalMaterial();

    glPushMatrix();
    glScalef(1.0f, 0.9f, 1.2f);
    glutSolidSphere(0.45f, 30, 30);
    glPopMatrix();

    glPushMatrix();
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

    setBladeMaterial();

    for (int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f);
        drawBlade();
        glPopMatrix();
    }

    setHubMaterial();
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
    setMetalMaterial();

    // pierœcienie (ju¿ metaliczne)
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

    // siatka – dalej metal, ale ju¿ pod lightingiem
    setMetalMaterial();
    glColor3f(0.85f, 0.85f, 0.88f);  // lekko jaœniejszy odcieñ, ale nadal materia³

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
    setMetalMaterial();
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

void drawTexturedFloor()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gFloorTexture);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.0f, -4.7f, 7.0f);
    glTexCoord2f(6.0f, 0.0f); glVertex3f(9.0f, -4.7f, 7.0f);
    glTexCoord2f(6.0f, 6.0f); glVertex3f(9.0f, -4.7f, -9.0f);
    glTexCoord2f(0.0f, 6.0f); glVertex3f(-9.0f, -4.7f, -9.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawTexturedBackWall()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gWallTexture);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.0f, -4.7f, -6.2f);
    glTexCoord2f(5.0f, 0.0f); glVertex3f(9.0f, -4.7f, -6.2f);
    glTexCoord2f(5.0f, 3.0f); glVertex3f(9.0f, 5.3f, -6.2f);
    glTexCoord2f(0.0f, 3.0f); glVertex3f(-9.0f, 5.3f, -6.2f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawTexturedLeftWall()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gWallTexture);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.8f, -4.7f, 7.0f);
    glTexCoord2f(5.0f, 0.0f); glVertex3f(-6.8f, -4.7f, -9.0f);
    glTexCoord2f(5.0f, 3.0f); glVertex3f(-6.8f, 5.3f, -9.0f);
    glTexCoord2f(0.0f, 3.0f); glVertex3f(-6.8f, 5.3f, 7.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawRoom()
{
    drawTexturedFloor();
    drawTexturedBackWall();
    drawTexturedLeftWall();
}

void drawFan()
{
    drawBase();
    drawStand();
    drawHead();
}


void drawLightMarkers()
{
    glDisable(GL_LIGHTING);

    glPushMatrix();
    glColor3f(1.0f, 0.95f, 0.6f);
    glTranslatef(0.0f, 4.3f, 0.0f);
    glutSolidSphere(0.12f, 12, 12);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.8f, 0.4f);
    glTranslatef(-4.0f, 2.0f, 0.0f);
    glutSolidSphere(0.12f, 12, 12);
    glPopMatrix();

    glEnable(GL_LIGHTING);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1000.0 / 700.0, 1.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(6.8, 3.3, 10.3,
        0.0, -1.6, -3.0,
        0.0, 1.0, 0.0);

    setLights();

    drawRoom();
    drawWindow();
    drawCurtain();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -3.0f);
    drawTable();
    drawFan();
    glPopMatrix();

    glutSwapBuffers();
}