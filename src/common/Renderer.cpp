#include "Renderer.h"

void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(RawModel* model) {
    glBindVertexArray(model->vaoID);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->vertexCount, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
