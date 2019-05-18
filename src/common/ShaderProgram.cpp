#include "ShaderProgram.h"

int ShaderProgram::loadShader(std::string filename, int type) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error opening file " << filename << std::endl;
    }
    std::stringstream ss;
    ss << input.rdbuf();
    input.close();

    const char* source = ss.str().c_str();

    int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);
    int compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE) {
        int logLen;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLen);
        std::vector<char> logMsg (logLen + 1);
        glGetShaderInfoLog(shaderID, logLen, NULL, &logMsg[0]);
        std::string logMsgStr (logMsg.begin(), logMsg.end());
        std::cerr << logMsgStr << std::endl;
        return -1;
    }
    return shaderID;
}

void ShaderProgram::bindAttribute(int attr, std::string varName) {
    glBindAttribLocation(programID, attr, varName.c_str());
}

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile) {
    vShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    fShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
    programID = glCreateProgram();
    glAttachShader(programID, vShaderID);
    glAttachShader(programID, fShaderID);
    glLinkProgram(programID);
    glValidateProgram(programID);
}

ShaderProgram::~ShaderProgram() {
    stop();
    glDetachShader(programID, vShaderID);
    glDetachShader(programID, fShaderID);
    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);
    glDeleteProgram(programID);
}

void ShaderProgram::start() {
    glUseProgram(programID);
}

void ShaderProgram::stop() {
    glUseProgram(0);
}
