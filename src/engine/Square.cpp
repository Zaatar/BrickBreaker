#include "Square.h"

void Square::updateCoordinates(float xDistance, float yDistance)
{
    xPos = translationMatrix[12] - xDistance;
    width = xDistance * 2;
    yPos = translationMatrix[13] - yDistance;
    height = yDistance * 2;
}

bool Square::checkCollision(Square &one, Square &two)
{
    bool collisionX = one.xPos + one.width >= two.xPos &&
                      two.xPos + two.width >= one.xPos;
    bool collisionY = one.yPos + one.height >= two.yPos &&
                      two.yPos + two.height >= one.yPos;
    return collisionX && collisionY;
}

void Square::load()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &pointsVbo);
    glBindBuffer(GL_ARRAY_BUFFER, pointsVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glGenBuffers(1, &colorsVbo);
    glBindBuffer(GL_ARRAY_BUFFER, colorsVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    shader.compileVertexShader();
    shader.compileFragmentShader();
    shader.createShaderProgram();
}

void Square::render()
{
    shader.use();
    int scaleMatrixLocation = glGetUniformLocation(shader.programId, "scaleMatrix");
    int translationMatrixLocation = glGetUniformLocation(shader.programId, "translationMatrix");
    glUniformMatrix4fv(scaleMatrixLocation, 1, GL_FALSE, scaleMatrix);
    glUniformMatrix4fv(translationMatrixLocation, 1, GL_FALSE, translationMatrix);
    glDrawArrays(GL_POLYGON, 0, 4);
}