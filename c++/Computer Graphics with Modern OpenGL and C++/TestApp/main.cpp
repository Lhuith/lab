#include <iostream>
// #include "test.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include "glm/gtx/string_cast.hpp"

using namespace std;

int main()
{
    // init GLFW
    if (!glfwInit())
    {
        printf("GLFW init failed! \n");
        glfwTerminate();
        return 1;
    }
    else
    {
        printf("GLFW initted! \n");
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    int initCode = glewInit();
    if (initCode != GLEW_OK)
    {
        printf("glew init failed: %d", initCode);
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }
    else
    {
        printf("GLEW initted! \n");
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    cout << "Hello World" << endl;
    glm::vec3 test = glm::vec3(0.0, 1.0, 0.0) + glm::vec3(1.0, 2.0, 1.0);
    cout << glm::to_string(test) << endl;

    return 0;
}