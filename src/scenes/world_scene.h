#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../input/inputhandler.h"
#include "../input/command.h"
#include "../tilemap/tilemap.h"
#include "../tilemap/tilemapeditor.h"
#include "../collision/boxcollider.h"
#include "../core/timer.h"
#include "../core/diceroller.h"

class World_Scene:public Scene{

public:
    /**
     * @brief Konstruktor world scene
     *
     * @param engine_ref Wskaznik na silnik
     */
    World_Scene(Engine *engine_ref);
    /**
     * @brief Destruktor world scene
     *
     */
    ~World_Scene();
    /**
     * @brief Metoda aktualizujaca scene
     *
     * @param deltatime deltatime
     * @return int
     */
    int processEvents(TimeStep deltatime) override;
    /**
     * @brief Metoda rysujaca scene
     *
     * @param deltatime deltatime
     */
    void draw(TimeStep deltatime) override;

private:
    float maxTimeToBattle;
    float elapsedTime;
    bool m_isInBattle;
    bool m_colisionWithTown;

    bool wonGame;

    Timer testTimer;
    Timer wonTimer;

    sf::Clock m_toBattleClock;
    Tilemap* testmap;
    InputHandler* m_inputhandler;
    EntityList* m_entitesPtr;
    TileMapEditor* m_mapeditor;
    sf::Sprite background_sprite;
    sf::Sprite wonGameSprite;

    sf::Music worldMapMusic;
    /**
     * @brief Metoda inicujaca scene
     *
     */
    void initData();
    /**
     * @brief Metoda input scene
     *
     */
    void input();
    /**
     * @brief Metoda czyszczaca scene
     *
     */
    void cleanupData();
};
