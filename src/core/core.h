#pragma once
//MAIN LIB
#include <iostream>
//ADD LIB
#include <GLAD/glad.h>
#include <glfw3.h>
//OWN headers

namespace DEngine{
    enum WINDOW_SIZE
    {
        WINDOW_WIDTH = 1280,
        WINDOW_HEIGHT = 720,
    };

    class EngineCore
    {
    private:
        GLFWwindow *window;

        bool initWindow();
        void mainLoop();
        void cleanup();

        void processInput(); 



        EngineCore(const EngineCore &) = delete;
        EngineCore &operator=(const EngineCore &) = delete;

    public:
        //bool window_open;

        void run();

        EngineCore();
        //window_open = true;     
    ~EngineCore();
};
}