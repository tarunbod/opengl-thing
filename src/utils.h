#ifndef UTILS_H
#define UTILS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "common/Camera.h"

#define VEC_3_0 glm::vec3(0.0f, 0.0f, 0.0f)

glm::mat4 getTransformMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);
glm::mat4 getViewMatrix(Camera *camera);

#endif