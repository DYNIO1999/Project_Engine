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
    bool isEnemyDead;

    Timer testTimer;
    Timer secondTimer;

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


    Scoreboard scorebaord;
    
};