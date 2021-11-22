#ifndef SQUARE_H
#define SQUARE_H

#include <GL/glew.h>
#include <iostream>

#include "Shader.h"

class Square
{
public:
    Square() = default;
    ~Square() = default;

    void init();
    void load();
    void render();

    void updateCoordinates(float xDistance, float yDistance);
    bool checkCollision(Square &one, Square &two);

    inline float getLastPositionX() { return lastPositionX; }
    inline float getLastPositionY() { return lastPositionY; }

protected:
    GLuint vao;
    GLuint vbo;
    Shader shader;

    float xPos;   //X at bottom left of drawn object
    float width;  //width
    float yPos;   //Y at bottom left of drawn object
    float height; //height
    float lastPositionX = 0.5f;
    float lastPositionY = 0.5f;
    float speedX = 1.0f;
    float speedY = 1.0f;

    float scaleMatrix[16] = {};

    float points[16] = {
        -0.5, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f};

    float translationMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};
};
#endif