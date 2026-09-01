#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();
    Window(GLint, GLint);

    int Init();

    void SwapBuffers() { glfwSwapBuffers(mainWindow); }

    GLfloat GetBufferWidth() { return bWidth; }
    GLfloat GetBufferHeight() { return bHeight; }

    bool GetShouldClose() { return glfwWindowShouldClose(mainWindow); }
    bool *GetKeys() { return keys; }
    GLfloat getXChange();
    GLfloat getYChange();

private:
    GLFWwindow *mainWindow; // is cleaned up
    GLFWmonitor **monitors; // is cleaned up
    GLint width, height;
    GLint bWidth, bHeight;
    bool keys[1024];

    GLfloat lastX;
    GLfloat lastY;
    GLfloat xChange;
    GLfloat yChange;
    bool mouseFirstMoved;

    void CreateCallBacks();

    int numMonitors;
    int GetMonitorsAndCount();

    static void HandleKeys(GLFWwindow *, int, int, int, int);
    static void HandleMouse(GLFWwindow *, double, double);
};
#endif