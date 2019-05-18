#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "../utils.h"
#include <fstream>
#include <sstream>
#include <vector>

class ShaderProgram {
private:
    static int loadShader(std::string filename, int type);
protected:
    virtual void bindAttributes() = 0;
    void bindAttribute(int attr, std::string varName);
public:
    int programID;
    int vShaderID;
    int fShaderID;
    ShaderProgram(std::string vertexFile, std::string fragmentFile);
    ~ShaderProgram();
    void start();
    void stop();
};

#endif