#ifndef LOADER_H
#define LOADER_H

#include "../utils.h"
#include "RawModel.h"

class Loader {
private:
    void storeDataInAttributeList(int attr, GLfloat data[], int size);
    void bindIndicesBuffer(int indices[], int size);
public:
    RawModel loadModelFromVertices(GLfloat vertices[], int vSize, int indices[], int iSize);
    int loadTexture(std::string filename);
};

#endif