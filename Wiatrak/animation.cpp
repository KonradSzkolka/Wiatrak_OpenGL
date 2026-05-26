#include <cmath>
#include <GL/glut.h>
#include "animation.h"
#include "app_state.h"

namespace
{
    constexpr float PI = 3.14159265358979323846f;
}

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

float angleDiff(float a, float b)
{
    float d = a - b;

    while (d > 180.0f) d -= 360.0f;
    while (d < -180.0f) d += 360.0f;

    return d;
}

float getTiltReduction()
{
    float upRatio = fabsf(gState.tiltAngle) / 20.0f;
    float reduction = upRatio * 0.75f;
    float result = 1.0f - reduction;

    if (result < 0.0f)
        result = 0.0f;

    return result;
}

float getTiltInfluence()
{
    // tiltAngle: 0 do -20
    float tiltAbs = fabsf(gState.tiltAngle);
    float tiltRad = tiltAbs * PI / 180.0f;

    float influence = cosf(tiltRad);

    // lekkie dodatkowe oslabienie, zeby efekt byl bardziej widoczny
    influence *= influence;

    if (influence < 0.15f)
        influence = 0.15f;

    return influence;
}

float getCurtainInfluence()
{
    const float targetAngle = -42.0f;
    const float range = 26.0f;

    float diff = fabsf(angleDiff(gState.headAngle, targetAngle));

    if (diff >= range)
        return 0.0f;

    return 1.0f - (diff / range);
}

float getCurtainStrength()
{
    float baseStrength = 0.0f;

    switch (gState.fanSpeedLevel)
    {
    case 1: baseStrength = 0.08f; break;
    case 2: baseStrength = 0.16f; break;
    case 3: baseStrength = 0.26f; break;
    default: baseStrength = 0.0f; break;
    }

    return baseStrength * getCurtainInfluence() * getTiltReduction();
}

void update()
{
    gState.bladeAngle += getBladeSpeed();
    if (gState.bladeAngle >= 360.0f)
        gState.bladeAngle -= 360.0f;

    if (gState.oscillationOn)
    {
        gState.headAngle += 0.24f * gState.headDirection;

        if (gState.headAngle >= 50.0f)
        {
            gState.headAngle = 50.0f;
            gState.headDirection = -1.0f;
        }
        else if (gState.headAngle <= -50.0f)
        {
            gState.headAngle = -50.0f;
            gState.headDirection = 1.0f;
        }
    }

    gState.curtainTime += 0.03f;

    glutPostRedisplay();
}