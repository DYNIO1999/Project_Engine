#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
     * \param deltatime deltatime.
     */
    void proccessEvents(TimeStep deltatime);
    /**
     * Metoda sluzy do renderowania
     * \param deltatime deltatime.
     */
    void draw(TimeStep deltatime);
    /** 
    * Glowny core aplikacji
    */
    void cleanUp();
    /**
     * Metoda sluzy do zmiany wielkosci okna
     * \param width szerokosc okna.
     * \param height wysokosc okna.
     */
    void changeWinSize(unsigned int width, unsigned int height);
    /**
     * Metoda sluzy do ustawiania pelnego ekranu
     * \param fullscreen zmienna boolowska okreslajaca czy ustawic fullscreen czy nie
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

    /**
     * SceneManager sluzy do obslugi scen gry
     */
    SceneManager *m_scene_manager;
    /**
     * Lasttime odmierzony po przejsciu calej petly gry
     */
    TimeStep m_lasttime;
    /**
     * CurrentTime aktualny czas
     */
    TimeStep m_currenttime;
    /**
     * Window czyli glowna klasa odnoszaca sie do okna gry
     */
    sf::RenderWindow* m_window;
    /**
     * Klasa videomode czyli klasa zapisujaca stan okna
     */
    sf::VideoMode* m_video_mode;
    /**
     * Wektro przetrzymujacy dostepne typy okna i rozdzielczosci
     */
    std::vector<sf::VideoMode> modes;

    /**
     * Glowny zegar silnika gry
     */
    sf::Clock m_engineClock;
    /**
     * Klasa event sluzy do obslugi eventow pobieranych od gracza czyli input
     */
    sf::Event event;
    /**
     * Primitywny render
     */
    PrimitiveRenderer* m_primitives_render;
    /**
     * Engine config przetrzymujacy informacje o silniku
     */
    EngineConfig m_engine_config;
    /**
     * Obiekt timestep przetrzymuje informajce od deltatime
     */
    TimeStep timestep;
    /**
     * Zmienna przetrzymuje informacje czy muzyka wlaczaona czy nie
     */
    bool isMusic;
    /**
     * Obiekt przetrzymuje informacje o zapisanej stanie gry
     */
    GameSaveData m_gameSaveData;
    /**  
    * Metoda zwraca nam deltaTime
    */
    TimeStep getDeltaTime(){
        return timestep;
    }
};
