#ifndef RENDERER_H
#define RENDERER_H

#include "../utils.h"
#include "RawModel.h"

class Renderer {
public:
    void prepare();
    void render(RawModel* model);
};

#endif