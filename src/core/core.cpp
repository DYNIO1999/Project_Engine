#include "core.h"
using namespace DEngine;

EngineCore::EngineCore(){
 window =nullptr;   
}
EngineCore::~EngineCore(){

}
bool EngineCore::initWindow(){
    if (!glfwInit())
    {
        std::cout<<"ERROR WHILE INIT GLFW!!"<<std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window= glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT, "DEngine", nullptr, nullptr);
    
    if(window == nullptr){
        std::cout << "ERROR WHILE CREATING WINDOW GLFW!!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    glViewport(0, 0,WINDOW_WIDTH, WINDOW_HEIGHT);
    return true;
}
void EngineCore::mainLoop(){
    while (!glfwWindowShouldClose(window))
    {
        processInput();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
void EngineCore::cleanup(){
    glfwTerminate();
}
void EngineCore::run(){
    initWindow();
    mainLoop();
    cleanup();
}
void EngineCore::processInput(){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}