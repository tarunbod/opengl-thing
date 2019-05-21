#include "StaticShader.h"

void StaticShader::bindAttributes() {
    bindAttribute(0, "position");
}

void StaticShader::getAllUniformLocations() {
    transformMatrixLoc = getUniformLocation("m_transform");
    projectionMatrixLoc = getUniformLocation("m_projection");
}

void StaticShader::loadTransformMatrix(glm::mat4 mat) {
    glUniformMatrix4fv(transformMatrixLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void StaticShader::loadProjectionMatrix(glm::mat4 mat) {
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(mat));
}
