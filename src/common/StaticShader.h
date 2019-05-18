#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#include "ShaderProgram.h"

class StaticShader: public ShaderProgram {
protected:
    void bindAttributes();
public:
    StaticShader(): ShaderProgram("shaders/static_v.txt", "shaders/static_f.txt") {};
};

#endif