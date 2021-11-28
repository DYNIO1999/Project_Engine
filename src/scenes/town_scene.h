#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <memory>
#include "scene.h"
#include "../core/core.h"
class EntityList;

class Town_Scene:public Scene
{
private:
    EntityList *m_entitesPtr;
    sf::Sprite background_sprite;
    sf::Clock m_clock;
    void initData();
public:
    Town_Scene(Engine* engine_ref);
    ~Town_Scene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;
    void input() override;
};

