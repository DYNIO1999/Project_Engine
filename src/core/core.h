#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>

#include "timestep.h"

namespace DEngine{

enum SCREEN_SIZE{
    SCREEN_WIDTH = 1280,
    SCREEN_HEIGHT = 720
};

class Engine
{
private:

public:
    //Engine(const Engine &) = delete;
    //Engine &operator=(const Engine &) = delete;

    Engine();
    ~Engine();
    void run();
    void mainLoop();
    void initWindow();
    void proccessEvents(TimeStep deltatime);
    void draw(TimeStep deltatime);
    void cleanUp();
    void changeWinSize(unsigned int width, unsigned int height, unsigned bitsPerPixel);
    void setFullScreen(bool fullscreen);
    void checkScreenModes();

    sf::Clock testclock;
    TimeStep m_lasttime;
    TimeStep m_currenttime; 
    sf::RenderWindow* m_window;
    sf::VideoMode* m_video_mode;
    std::vector<sf::VideoMode> modes;
    int counter;
};
};

