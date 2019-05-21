#define GLFW_DLL

#include "utils.h"
#include "RawModel.h"
#include "Loader.h"
#include "Renderer.h"
#include "StaticShader.h"

glm::mat4 getTransformMatrix(glm::vec3 translation = VEC_3_0, float rx = 0, float ry = 0, float rz = 0, float scale = 1) {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::translate(mat, translation);
    mat = glm::rotate(mat, glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    mat = glm::rotate(mat, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
    mat = glm::scale(mat, glm::vec3(scale, scale, scale));
    return mat;
}

GLFWwindow* window;

bool windowSetup() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize glfw" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    // Open a window and create its OpenGL context
    window = glfwCreateWindow(mode->width, mode->height, "Tutorial 01", monitor, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return false;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    return true;
}

void drawSetup() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 0.9f, 1.0f);
}

int main() {
    if (!windowSetup()) {
        return 1;
    }

    drawSetup();

    Loader loader;
    Renderer renderer;
    StaticShader shader;
    shader.validate();

    GLfloat points[] = {
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f
    };

    int indices[] = {
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7,
        4, 0, 3,
        4, 3, 7,
        1, 5, 6,
        1, 6, 2,
        3, 2, 6,
        3, 6, 7,
        5, 1, 0,
        5, 0, 4
    };

    int vSize = sizeof(points) / sizeof(GLfloat);
    int iSize = sizeof(indices) / sizeof(int);

    RawModel model = loader.loadModelFromVertices(points, vSize, indices, iSize);

    float x = 0;

    do {
        renderer.prepare();
        shader.start();
        shader.loadTransformMatrix(getTransformMatrix(glm::vec3(0.0f, 0.0f, -5.0f), x, x));
        shader.loadProjectionMatrix(renderer.getProjectionMatrix());
        renderer.render(&model);
        shader.stop();
        glfwSwapBuffers(window);
        glfwPollEvents();
        x += 0.10f;
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    return 0;
}
