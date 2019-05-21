#ifndef ENTITY_H
#define ENTITY_H

#include "../utils.h"
#include "RawModel.h"

class Entity {
public:
    RawModel *model;
    glm::vec3 position;
    float rx;
    float ry;
    float rz;
    float scale;
    Entity(RawModel *m, glm::vec3 pos, float _rx, float _ry, float _rz, float s);
    void translateBy(float dx, float dy, float dz);
    void rotateBy(float dx, float dy, float dz);
};

#endif