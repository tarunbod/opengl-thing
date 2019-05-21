#define GLFW_DLL

#include "utils.h"
#include "RawModel.h"
#include "Loader.h"
#include "Renderer.h"
#include "StaticShader.h"
#include "Camera.h"

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
    StaticShader shader;
    Camera camera;
    Renderer renderer;
    shader.validate();

    GLfloat points[] = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 1.0f,
        -0.5f, -0.5f, 1.0f,
        0.5f, -0.5f, 1.0f,
        0.5f, 0.5f, 1.0f
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
    Entity entity(&model, glm::vec3(0.0f, 0.0f, -5.0f), 0.0f, 0.0f, 0.0f, 1.0f);

    do {
        renderer.prepare();
        renderer.render(&entity, &shader, &camera);
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        camera.update(window);
        entity.rotateBy(1.0f, 1.0f, 0.0f);
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    return 0;
}
