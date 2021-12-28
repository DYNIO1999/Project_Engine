#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../collision/boxcollider.h"
#include "../gui/buttonGUI.h"

class Button;

enum BATTLE_BUTTON_TYPES
{
    BATTLE_END_TURN,
};

enum BATTLE_MAP_TYPES{
    DESERT_MAP_TYPE,
    MOUNTAIN_MAP_TYPE,
};

class Battle_Scene : public Scene
{
public:
    Battle_Scene(Engine *engine_ref);
    Battle_Scene(Engine *engine_ref, int battleMapType, int numberEnemies);
    int processEvents(TimeStep deltatime);
    void draw(TimeStep deltatime);
    void input();
    ~Battle_Scene();
private:

    sf::Vector2f m_mousePosition;
    sf::Sprite m_background;
    void initData();
    void cleanupData();

    int m_battleMapType;
    int m_numberEnemies;

    std::vector<Button*> m_buttonList;
    sf::RectangleShape m_GUIbar;
    EntityList *m_entitesPtr;
};