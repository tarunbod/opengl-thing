#ifndef RENDERER_H
#define RENDERER_H

#include "../utils.h"
#include "RawModel.h"

class Renderer {
private:
    glm::mat4 projectionMatrix;
public:
    static constexpr float FOV = 70.0f;
    static constexpr float NEAR_PLANE = 0.1f;
    static constexpr float FAR_PLANE = 1000.0f;
    Renderer();
    void prepare();
    void render(RawModel* model);
    glm::mat4 getProjectionMatrix();
};

#endif