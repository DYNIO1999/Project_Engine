#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../collision/boxcollider.h"


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
    sf::Sprite m_background;
    void initData();
    void cleanupData();

    int m_battleMapType;
    int m_numberEnemies;
};