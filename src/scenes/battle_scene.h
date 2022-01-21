#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../collision/boxcollider.h"
#include "../gui/buttonGUI.h"
#include <SFML/Audio.hpp>
#include "../core/diceroller.h"
#include "../core/timer.h"
#include "../objects/potion.h"
#include "../gui/scoreboard.h"

class Button;

enum BATTLE_TURN{
    BATTLE_PLAYER_TURN,
    BATTLE_ENEMY_TURN
};

enum BATTLE_BUTTON_TYPES
{
    BATTLE_END_TURN,
};

enum BATTLE_MAP_TYPES{
    DESERT_MAP_TYPE,
    MOUNTAIN_MAP_TYPE,
};

enum BATTLE_STATES
{
    BATTLE_DEFAULT_STATE,
    BATTLE_WON_STATE,
    BATTLE_LOST_STATE,
};

class Battle_Scene : public Scene
{
public:
    /**
     * @brief Konstruktor sceny bitwy
     *
     * @param engine_ref wskaznik na silnik gry
     */
    Battle_Scene(Engine *engine_ref);
    /**
     * @brief Konstruktor sceny bitwy
     *
     * @param engine_ref wskanizk na silnik gry
     * @param battleMapType typ mapy
     * @param numberEnemies ilosc przeciwnikow
     */
    Battle_Scene(Engine *engine_ref, int battleMapType, int numberEnemies);
    /**
     * @brief Metoda aktualizujaca scene bitwy
     *
     * @param deltatime deltatime
     * @return int
     */
    int processEvents(TimeStep deltatime);
    /**
     * @brief Metoda rysujaca scene bitwy
     *
     * @param deltatime deltatime
     */
    void draw(TimeStep deltatime);
    /**
     * @brief Metoda zbierajaca output od gracza
     *
     */
    void input();
    /**
     * Destruktor klasy bitwy
     */
    ~Battle_Scene();
private:
    /**
     * Pozycja myszki
     */
    sf::Vector2f m_mousePosition;
    /**
     * Obiekt sprite
     */
    sf::Sprite m_background;
    /**
     * Metoda inicujaca scene bitwy
     */
    void initData();
    /**
     * Metoda czyszczaca scene bitwy
     */
    void cleanupData();

    int m_battleMapType;
    int m_numberEnemies;

    std::vector<Potion*> m_potionList;

    std::vector<Button*> m_buttonList;
    sf::RectangleShape m_GUIbar;
    EntityList *m_entitesPtr;
    std::string enemyObjName = "ENEMY_";
    std::string playerObjName = "PLAYER_BATTLE";
    std::string currentObjName;
    std::string enemyKilledObjName;

    int currentTurn;
    bool clickedOnEnemy;
    bool clickedOnPotion;
    bool endTurn;
    bool objMoved;
    bool allowEndTurn;
    bool inAnimation;
    bool isDeath;
    bool waitToMove;
    std::vector<int> deletedIndex;
    bool allowClickOnEnemy;
    int currentNumberEnemies;
    bool allowUsePotion;
    bool isPlayerDead;

    Timer testTimer;
    Timer secondTimer;
    Timer wonTimer;
    Timer lostTimer;

    sf::Vector2f playerstartPos;
    sf::Vector2f enemystartPos;

    int potionIndexToRemove;

    int currentEnemyIndex;

    std::shared_ptr<sf::Texture> pPlayerAttackTexture;
    std::shared_ptr<sf::Texture> pPlayerDeathTexture;
    std::shared_ptr<sf::Texture> pPlayerHitTexture;
    std::shared_ptr<sf::Texture> pPlayerIdleTexture; 
    std::shared_ptr<sf::Texture> pEnemyIdleTexture;
    std::shared_ptr<sf::Texture> pEnemyHitTexture; 
    std::shared_ptr<sf::Texture> pEnemyAttackTexture;
    std::shared_ptr<sf::Texture> pEnemyDeathTexture;
    std::shared_ptr<sf::Texture> pPotionTexture;

    std::shared_ptr<sf::Texture> pWonTexture;
    std::shared_ptr<sf::Texture> pLostTexture;

    sf::Sprite m_wonSprite;
    sf::Sprite m_lostSprite;

    Scoreboard scorebaord;
    int m_battleSceneState;

    sf::Sound swordHit;
    sf::Sound deathSound;

    sf::Music battleMusic;
};