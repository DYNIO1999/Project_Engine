#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>

#include "timestep.h"

#include "../scenes/scene_manager.h"
#include "../scenes/world_scene.h"
#include "entitylist.h"
#include "../objects/player.h"
//#include "../objects/drawable.h"

//namespace DEngine{
enum SCREEN_SIZE{
    SCREEN_WIDTH = 1280,
    SCREEN_HEIGHT = 720
};

class Scene;

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

    SceneManager* m_scene_manager;
    sf::Clock testclock;
    TimeStep m_lasttime;
    TimeStep m_currenttime; 
    sf::RenderWindow* m_window;
    sf::VideoMode* m_video_mode;
    std::vector<sf::VideoMode> modes;


    EntityList* m_entity_manager;
    int counter;
    //Object *obj;
    //Object *obj2;
    float color[3] = {0.0f, 0.0f, 0.0f};
    float color2[3] = {0.0f, 0.0f, 0.0f};
    float pos[2] ={0.0f,0.0f};
    float size[2] = {0.0f, 0.0f};
    float pos1[2] = {0.0f, 0.0f};
    float size1[2] = {0.0f, 0.0f};
};
//};

