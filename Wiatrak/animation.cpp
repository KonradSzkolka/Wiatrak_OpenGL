#include <cmath>
#include <GL/glut.h>
#include "animation.h"
#include "app_state.h"

float getBladeSpeed()
{
    switch (gState.fanSpeedLevel)
    {
    case 1: return 4.0f;
    case 2: return 10.0f;
    case 3: return 20.0f;
    default: return 0.0f;
    }
}

float getCurtainInfluence()
{
    float targetAngle = 28.0f;
    float range = 18.0f;

    float diff = fabs(gState.headAngle - targetAngle);

    if (diff >= range)
        return 0.0f;

    return 1.0f - (diff / range);
}

float getCurtainStrength()
{
    float baseStrength = 0.0f;

    switch (gState.fanSpeedLevel)
    {
    case 1: baseStrength = 0.05f; break;
    case 2: baseStrength = 0.11f; break;
    case 3: baseStrength = 0.18f; break;
    default: baseStrength = 0.0f; break;
    }

    return baseStrength * getCurtainInfluence();
}

void update()
{
    gState.bladeAngle += getBladeSpeed();
    if (gState.bladeAngle >= 360.0f)
        gState.bladeAngle -= 360.0f;

    if (gState.oscillationOn)
    {
        gState.headAngle += 0.18f * gState.headDirection;

        if (gState.headAngle >= 35.0f)
        {
            gState.headAngle = 35.0f;
            gState.headDirection = -1.0f;
        }
        else if (gState.headAngle <= -35.0f)
        {
            gState.headAngle = -35.0f;
            gState.headDirection = 1.0f;
        }
    }

    gState.curtainTime += 0.03f;

    glutPostRedisplay();
}