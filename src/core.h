#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace DEngine{

enum SCREEN_SIZE{
    SCREEN_WIDTH = 1280,
    SCREEN_HEIGHT = 720
};

class Engine
{
private:

public:
    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    Engine();
    ~Engine();
    void run();
    void mainLoop();
    void initWindow();
    void proccessEvents();
    void draw();
    void cleanUp();


    sf::RenderWindow* m_window;
    sf::VideoMode* m_video_mode;
};
};

