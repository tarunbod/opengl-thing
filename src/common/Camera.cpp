#include "Camera.h"

void Camera::update(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        position[2] += 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        position[2] -= 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        position[0] += 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        position[0] -= 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        position[1] += 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        position[1] -= 0.005f;
    }
}