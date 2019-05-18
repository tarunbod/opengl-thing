#ifndef RAW_MODEL_H
#define RAW_MODEL_H

#include "../utils.h"

class RawModel {
public:
    GLuint vaoID;
    int vertexCount;
    RawModel(GLuint id, int count);
    ~RawModel();
};

#endif