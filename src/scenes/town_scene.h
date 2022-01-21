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

    sf::Music townMusic;

    /**
     * @brief Metoda inicujaca scene town
     *
     */
    void initData();
    /**
     * @brief Metoda czyszczaca scene
     *
     */
    void cleanUp();
public:
    /**
     * @brief Konstruktor sceny
     *
     * @param engine_ref Wskaznik na silnik gry
     */
    Town_Scene(Engine* engine_ref);
    /**
     * @brief Destruktor sceny
     *
     */
    ~Town_Scene();
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
    /**
     * @brief Metoda input scene
     *
     */
    void input() override;
};

