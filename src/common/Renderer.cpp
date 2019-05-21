#include "Renderer.h"

Renderer::Renderer() {
    projectionMatrix = glm::perspective(glm::radians(FOV), 1366.0f / 768.0f, NEAR_PLANE, FAR_PLANE);
    const float* p = glm::value_ptr(projectionMatrix);
    for (int i = 0; i < 16; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(RawModel* model) {
    glBindVertexArray(model->vaoID);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->vertexCount, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

glm::mat4 Renderer::getProjectionMatrix() {
    return projectionMatrix;
}
