#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <memory>
#include "scene.h"
#include "../gui/buttonGUI.h"

class EntityList;

class Town_Scene:public Scene
{
private:
    EntityList *m_entitesPtr;
    sf::Sprite background_sprite;
    sf::Sprite m_inventorySprite;
    sf::Clock m_clock;
    Button attackbutton;
    Button healthbutton;
    sf::Vector2f m_mousePosition;
    std::vector<Button *> m_buttonnList;
    sf::Text m_attackText;
    sf::Text m_healthText;
    void initData();
public:
    Town_Scene(Engine* engine_ref);
    ~Town_Scene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;
    void input() override;
};

