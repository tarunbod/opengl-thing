#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Camera {
public:
    glm::vec3 position;
    float pitch;
    float yaw;
    float roll;
    void update(GLFWwindow *window);
};

#endif