#pragma once
//MAIN LIB
#include <iostream>
//ADD LIB
#include <GLAD/glad.h>
#include <glfw3.h>
//OWN headers
#include "winsize.h"

namespace DEngine{
    enum WINDOW_SIZE
    {
        WINDOW_WIDTH = 1280,
        WINDOW_HEIGHT = 720,
    };

    enum FRAME_RATE{
        ENGINE_FPS_CAP = 60,
    };

    class EngineCore
    {
    private:
        GLFWwindow *window;
        GLFWmonitor* monitor;

        bool initWindow();
        void mainLoop();
        void cleanup();

        void processInput(); 

        EngineCore(const EngineCore &) = delete;
        EngineCore &operator=(const EngineCore &) = delete;

    public:
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        int SCREEN_POS_X;
        int SCREEN_POS_Y; 
        //WindowManager* engineWinManager;
        bool fullscreen; 
        void run();
        EngineCore();
        ~EngineCore();
};
}