#include "window.hpp"
#define WINDOW_PTR Window *window_ptr = static_cast<Window *>(glfwGetWindowUserPointer(w))

Window::Window()
{
    width = 800;
    height = 600;

    for (size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }

    mouseFirstMoved = true;
    xChange = 0;
    yChange = 0;
}
Window::Window(GLint w, GLint h)
{
    width = w;
    height = h;

    for (size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }

    mouseFirstMoved = true;
    xChange = 0;
    yChange = 0;
}
Window::~Window()
{
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    delete monitors;
}

int Window::Init()
{
    // init GLFW
    if (!glfwInit())
    {
        printf("GLFW init failed!");
        glfwTerminate();
        return 1;
    }

    // setup glfw window properties
    // opengl versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // hide glfw flag
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    // core profile = no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    int monitorCount = GetMonitorsAndCount();
    // https://stackoverflow.com/questions/67239235/how-do-i-create-a-centered-glfw-window
    // thanks msbit
    // custom set position of window on second screen

    int monitorX, monitorY, vWindowWidth, vWindowHeight;
    const GLFWvidmode *videoMode; // is cleaned up

    if (monitorCount >= 2)
    {
        videoMode = glfwGetVideoMode(monitors[1]);
        vWindowWidth = videoMode->width / 1.5;
        vWindowHeight = vWindowWidth / 16 * 9;
    }

    glfwGetMonitorPos(monitors[1], &monitorX, &monitorY);

    mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);

    if (!mainWindow)
    {
        printf("GLFW window creation window failed");
        glfwTerminate();
        return 1;
    }

    // reset the window hints to default
    glfwDefaultWindowHints();

    if (monitorCount >= 2)
    {
        glfwSetWindowPos(mainWindow,
                         monitorX + (videoMode->width - vWindowWidth) / 2,
                         monitorY + (videoMode->height - vWindowHeight) / 2);
    }

    // unhide window
    glfwShowWindow(mainWindow);

    // get buffer size information
    glfwGetFramebufferSize(mainWindow, &bWidth, &bHeight);

    // set context for glew to use
    glfwMakeContextCurrent(mainWindow);

    // handle key + mouse input
    CreateCallBacks();

    glfwFocusWindow(mainWindow);
    glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(mainWindow, width / 2, height / 2);

    // allow modern extension features;
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        printf("glew init failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    // set up viewport size
    glViewport(0, 0, bWidth, bHeight);

    // sets static pointer within GLFW, that be later grabbed in keys/mouse function call backs
    //  please look at WINDOW_PTR #define to see what that looks like
    glfwSetWindowUserPointer(mainWindow, this);

    delete videoMode;
    return 0;
}

int Window::GetMonitorsAndCount()
{
    monitors = glfwGetMonitors(&numMonitors);
    return numMonitors;
}

void Window::CreateCallBacks()
{
    glfwSetKeyCallback(mainWindow, HandleKeys);
    glfwSetCursorPosCallback(mainWindow, HandleMouse);
}

GLfloat Window::getXChange()
{
    GLfloat change = xChange;
    xChange = 0.0f;
    return change;
}
GLfloat Window::getYChange()
{
    GLfloat change = yChange;
    yChange = 0.0f;
    return change;
}

void Window::HandleKeys(GLFWwindow *w, int key, int code, int act, int mode)
{
    WINDOW_PTR;

    if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(w, GL_TRUE);
    }

    if (key >= 0 && key < 1024)
    {
        if (act == GLFW_PRESS)
        {
            window_ptr->keys[key] = true;
        }
        else if (act == GLFW_RELEASE)
        {
            window_ptr->keys[key] = false;
        }
    }
}

void Window::HandleMouse(GLFWwindow *w, double x, double y)
{
    WINDOW_PTR;

    if (window_ptr->mouseFirstMoved)
    {
        window_ptr->lastX = x;
        window_ptr->lastY = y;
        window_ptr->mouseFirstMoved = false;
    }

    window_ptr->xChange = x - window_ptr->lastX;
    window_ptr->yChange = window_ptr->lastY - y;

    window_ptr->lastX = x;
    window_ptr->lastY = y;
}