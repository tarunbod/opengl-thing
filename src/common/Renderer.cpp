#include "Renderer.h"

Renderer::Renderer() {
    projectionMatrix = glm::perspective(glm::radians(FOV), 1366.0f / 768.0f, NEAR_PLANE, FAR_PLANE);
}

void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Entity *entity, StaticShader *shader, Camera *camera) {
    RawModel *model = entity->model;

    shader->start();
    shader->loadTransformMatrix(getTransformMatrix(entity->position, entity->rx, entity->ry, entity->rz, entity->scale));
    shader->loadProjectionMatrix(getProjectionMatrix());
    shader->loadViewMatrix(getViewMatrix(camera));

    glBindVertexArray(model->vaoID);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->vertexCount, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);

    shader->stop();
}

glm::mat4 Renderer::getProjectionMatrix() {
    return projectionMatrix;
}
