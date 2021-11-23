#include "Brick.h"

void Brick::init(float xPos, float yPos)
{
    for (int i = 0; i < 16; ++i)
    {
        scaleMatrix[i] = brickScaleMatrix[i];
    }
    translationMatrix[12] = xPos;
    translationMatrix[13] = yPos;
    updateCoordinates(XDISTANCE, YDISTANCE);
}