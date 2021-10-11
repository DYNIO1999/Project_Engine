#pragma once
#include <glfw3.h>
namespace DEngine{
class WindowManager
{
private:
    GLFWmonitor* primary_monitor;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
    GLFWwindow* win_ref;
    WindowManager(GLFWwindow* win_ref, int width, int height);
    ~WindowManager();
    void changeWinSize(const  int width, const  int height);
    int getWinWidth();
    int getWinHeigh();
    GLFWmonitor* getCurrentMonitor();
    
};
};