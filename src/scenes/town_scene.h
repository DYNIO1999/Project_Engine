#pragma once
#include "scene.h"
#include "../gui/buttonGUI.h"
#include "../gui/scoreboard.h"

enum TOOWN_BUTTON_TYPES
{
    TOWN_BUTTON_ADD_ATTACK,
    TOWN_BUTTON_ADD_HEALTH,
    TOWN_BUTTON_SAVE,
    TOWN_BUTTON_EXIT,
};

class EntityList;

class Town_Scene:public Scene
{
private:
    EntityList *m_entitesPtr;
    sf::Sprite background_sprite;
    sf::Sprite m_inventorySprite;
    sf::Clock m_clock;
    sf::Vector2f m_mousePosition;
    std::vector<Button*> m_buttonList;

    sf::Text m_attackText;
    sf::Text m_healthText;
    sf::Text m_experienceText;
    
    Scoreboard healthStats;
    Scoreboard attackStats;
    Scoreboard experienceStats;

    void initData();
    void cleanUp();
public:
    Town_Scene(Engine* engine_ref);
    ~Town_Scene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;
    void input() override;
};

