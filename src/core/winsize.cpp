#include "winsize.h"
using namespace DEngine;

WindowManager::WindowManager(GLFWwindow* win_ref, int width, int height){
    primary_monitor = glfwGetPrimaryMonitor();
    this->win_ref=win_ref;
    this->SCREEN_WIDTH=width;
    this->SCREEN_HEIGHT=height;
}
WindowManager::~WindowManager(){

}

void WindowManager::changeWinSize(const int width, const  int height){
    glfwSetWindowSize(win_ref, width, height);
    glfwGetWindowSize(win_ref,&SCREEN_WIDTH, &SCREEN_HEIGHT);
}
int WindowManager::getWinWidth(){   
    return this->SCREEN_WIDTH;
}
int WindowManager::getWinHeigh(){
    return this->SCREEN_HEIGHT;

}
GLFWmonitor* WindowManager::getCurrentMonitor(){
    return this->primary_monitor;
}