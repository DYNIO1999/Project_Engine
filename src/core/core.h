#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"



#include "timestep.h"

#include "../scenes/scene_manager.h"
#include "../scenes/world_scene.h"
#include "../scenes/engine_demo.h"
#include "../renderer/primitiveRenderer.h"
#include "../objects/player.h"
#include "../input/inputhandler.h"
#include "entitylist.h"
#include "../json.hpp"
#include "engineconfig.h"
#include "../resource/resource_manager.h"

class Scene;

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
    void proccessEvents(TimeStep deltatime);
    void draw(TimeStep deltatime);
    void cleanUp();
    void changeWinSize(unsigned int width, unsigned int height);
    void setFullScreen(bool fullscreen);
    void checkScreenModes();
    void loadConfig();
    void saveConfig();
    
    SceneManager *m_scene_manager;
    TimeStep m_lasttime;
    TimeStep m_currenttime; 
    sf::RenderWindow* m_window;
    sf::VideoMode* m_video_mode;
    std::vector<sf::VideoMode> modes;

    PrimitiveRenderer* m_primitives_render;
    EntityList* m_entity_manager;
    InputHandler* m_input_handler;
    EngineConfig m_engine_config;
    TimeStep timestep;
    sf::Clock m_engineClock;

    TimeStep getDeltaTime(){
        return timestep;
    }
};
