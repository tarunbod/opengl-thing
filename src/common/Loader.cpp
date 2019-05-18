#include "Loader.h"

RawModel Loader::loadModelFromVertices(GLfloat vertices[], int vSize, int indices[], int iSize) {
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    bindIndicesBuffer(indices, iSize * sizeof(int));
    storeDataInAttributeList(0, vertices, vSize * sizeof(GLfloat));
    glBindVertexArray(0);
    RawModel model(vaoID, iSize);
    return model;
}

void Loader::storeDataInAttributeList(int attr, GLfloat data[], int size) {
    // TODO: delete buffers on destruct
    GLuint vboID;
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attr, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::bindIndicesBuffer(int indices[], int size) {
    // TODO: delete buffers on destruct
    GLuint vboID;
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

