#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>

class Shader
{
public:
    Shader() = default;
    ~Shader() = default;

    GLuint programId;

    void compileVertexShader();
    void compileFragmentShader();
    void createShaderProgram();

    Shader &use();

private:
    GLuint vs;
    GLuint fs;

    const char *vertexShader =
        "#version 430\n"
        "layout(location = 0) in vec3 vertexPosition;"
        "layout(location = 1) in vec3 colors;"
        "uniform mat4 scaleMatrix;"
        "uniform mat4 translationMatrix;"
        "out vec3 color;"
        "void main() {"
        "   color = colors;"
        "   gl_Position = translationMatrix * scaleMatrix * vec4(vertexPosition, 1.0);"
        "}";

    const char *fragmentShader =
        "#version 430\n"
        "uniform vec3 color;"
        "out vec4 fragmentColor;"
        "void main() {"
        "   fragmentColor = vec4(color,1.0f);"
        "}";
};
#endif