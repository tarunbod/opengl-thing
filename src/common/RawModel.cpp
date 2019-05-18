#include "RawModel.h"

RawModel::RawModel(GLuint id, int count) {
    vaoID = id;
    vertexCount = count;
}

RawModel::~RawModel() {
    glDeleteVertexArrays(1, &vaoID);
}
