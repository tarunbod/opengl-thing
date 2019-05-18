#define GLFW_DLL

#include "utils.h"
#include "RawModel.h"
#include "Loader.h"
#include "Renderer.h"
#include "StaticShader.h"

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
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
}

int main() {
    if (!windowSetup()) {
        return 1;
    }

    drawSetup();

    GLfloat points[] = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f
    };

    int indices[] = {
        0, 1, 3,
        3, 1, 2
    };

    int vSize = sizeof(points) / sizeof(GLfloat);
    int iSize = sizeof(indices) / sizeof(int);

    Loader loader;
    Renderer renderer;
    StaticShader shader;

    RawModel model = loader.loadModelFromVertices(points, vSize, indices, iSize);

    do {
        renderer.prepare();
        shader.start();
        renderer.render(&model);
        shader.stop();
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    return 0;
}
