#include "utils.h"

glm::mat4 getTransformMatrix(glm::vec3 translation = VEC_3_0, float rx = 0, float ry = 0, float rz = 0, float scale = 1) {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::translate(mat, translation);
    mat = glm::rotate(mat, glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
    mat = glm::scale(mat, glm::vec3(scale, scale, scale));
    return mat;
}

glm::mat4 getViewMatrix(Camera *camera) {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::rotate(mat, glm::radians(camera->pitch), glm::vec3(1.0f, 0.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(camera->yaw), glm::vec3(0.0f, 1.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(camera->roll), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 negativeCamPos = glm::vec3(-camera->position.x, -camera->position.y, -camera->position.z);
    mat = glm::translate(mat, negativeCamPos);
    return mat;
}
