#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#include "../utils.h"
#include "ShaderProgram.h"

class StaticShader: public ShaderProgram {
private:
    int transformMatrixLoc;
    int projectionMatrixLoc;
protected:
    void bindAttributes();
    void getAllUniformLocations();
public:
    StaticShader(): ShaderProgram("shaders/static_v.txt", "shaders/static_f.txt") {};
    void loadTransformMatrix(glm::mat4 mat);
    void loadProjectionMatrix(glm::mat4 mat);
};

#endif