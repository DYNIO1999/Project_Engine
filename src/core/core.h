#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include "timestep.h"

#include "../scenes/scene_manager.h"
#include "../scenes/engine_demo.h"
#include "../scenes/main_menu_scene.h"
#include "../renderer/primitiveRenderer.h"
#include "../input/inputhandler.h"
#include "entitylist.h"
#include "../json.hpp"
#include "engineconfig.h"
#include "../resource/resource_manager.h"
#include "gamesavedata.h"


/** Pre-Definicja klasy Scene
*/
class Scene;
/** Core
 * Klasa silnika 
 * Glowny core aplikacji
*/
class Engine
{
private:

public:

    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    Engine();
    ~Engine();
    /** 
     *Metoda run sluzy do wywoalania metod initWindow oraz mainLoop oraz cleanUP
    **/
    void run();
    /** 
    * Metoda do petli gry
    * 
    */
    void mainLoop();
    /** 
    * Metoda do inicjacji okna
    */
    void initWindow();
    /** 
    * Metoda sluzy do pobierania inputu i przeprowadzania update na podstawie odebranych danych 
    */
    void proccessEvents(TimeStep deltatime);
    /** 
    * Metoda sluzy do renderowania
    */
    void draw(TimeStep deltatime);
    /** 
    * Glowny core aplikacji
    */
    void cleanUp();
    /**  
    * Metoda sluzy do zmiany wielkosci okna
    */
    void changeWinSize(unsigned int width, unsigned int height);
    /** 
    * Metoda sluzy do ustawiania pelnego ekranu
    */
    void setFullScreen(bool fullscreen);
    /**  
    * Sprawdzenie jakie wsparcie ma nasz ekran
    */
    void checkScreenModes();
    /**  
    * Zaladowanie danych potrzebny do inicjacji okna 
    */
    void loadConfig();
    /**  
    * Zapisanie danych potrzebny do inicjacji okna
    */
    void saveConfig();
    
    SceneManager *m_scene_manager;
    TimeStep m_lasttime;
    TimeStep m_currenttime; 
    sf::RenderWindow* m_window;
    sf::VideoMode* m_video_mode;
    std::vector<sf::VideoMode> modes;
    
    sf::Clock m_engineClock;
    sf::Event event;
    
    PrimitiveRenderer* m_primitives_render;
    EngineConfig m_engine_config;
    TimeStep timestep;

    GameSaveData m_gameSaveData;

    /**  
    * Metoda zwraca nam deltaTime
    */
    TimeStep getDeltaTime(){
        return timestep;
    }
};
