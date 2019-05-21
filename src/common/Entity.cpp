#include "Entity.h"

Entity::Entity(RawModel *m, glm::vec3 pos, float _rx, float _ry, float _rz, float s) {
    model = m;
    position = pos;
    rx = glm::radians(_rx);
    ry = glm::radians(_ry);
    rz = glm::radians(_rz);
    scale = s;
}

void Entity::translateBy(float dx, float dy, float dz) {
    position[0] += dx;
    position[1] += dy;
    position[2] += dz;
}

void Entity::rotateBy(float dx, float dy, float dz) {
    rx += glm::radians(dx);
    ry += glm::radians(dy);
    rz += glm::radians(dz);
}
