#pragma once

struct AppState
{
    float curtainTime = 0.0f;
    float tiltAngle = 0.0f;
    float bladeAngle = 0.0f;

    int fanSpeedLevel = 0;   // 0,1,2,3
    bool oscillationOn = true;

    float headAngle = 0.0f;
    float headDirection = 1.0f;
};

extern AppState gState;