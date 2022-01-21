#pragma once
#include "object.h"
#include "../input/inputtypes.h"
#include "../core/core.h"
#include "../animation/animation.h"
#include "../gui/healthbar.h"
#include "../core/gamesavedata.h"

enum PLAYER_TYPE
{
    PLAYER_WORLD_MAP_TYPE,
    PLAYER_DEMO_TYPE,
    PLAYER_BATTLE_TYPE,
};

enum PLAYER_ANIMATION_STATES{
    PLAYER_ANIMATION_IDLE,
    PLAYER_ANIMATION_ATTACK,
    PLAYER_ANIMATION_DEATH,
    PLAYER_ANIMATION_HIT,
};
/**
 * Klasa gracza
 */
class Player :public Object
{
private:

public:
    /**
     * Konstruktor klasy gracza
     * \param texturePtr wskaznik na texture
     * \param pos pozycja
     * \param size szerkosc
     * \param enginePtr wskaznik na silnik
     * \param engineDemo stan silnika
     */
    Player(std::shared_ptr<sf::Texture> texturePtr,sf::Vector2f pos, sf::Vector2f size, Engine* enginePtr, int engineDemo){
        m_enginePtr = enginePtr;
        m_pos = pos;                                 
        m_size = size;
        m_movestate = NO_INPUT;
        m_pTexture=texturePtr;
        m_velocity = 300.0f;
        m_playerSprite.setTexture(*m_pTexture);
        m_playerSprite.setPosition(m_pos-sf::Vector2f(5,5));
        m_playerCamera.setCenter(m_pos);
        m_playerCamera.setSize(sf::Vector2f(m_enginePtr->m_window->getSize().x, m_enginePtr->m_window->getSize().y));
        
        //DEBUG
        m_playerShape.setFillColor(sf::Color::Transparent);
        m_playerShape.setOutlineColor(sf::Color::Red);
        m_playerShape.setOutlineThickness(1.0f);

        BoxCollider temp(m_pos.x,m_pos.y,m_size.x,m_size.y);
        m_colisionBox = temp;
        enginedemo = engineDemo;

        if(enginedemo==PLAYER_DEMO_TYPE){
        m_playerAnimation = new Animation(m_pTexture, sf::Vector2u(4, 1), 0.1f);

        }else if(enginedemo ==PLAYER_BATTLE_TYPE){
        
        m_animationstate = PLAYER_ANIMATION_IDLE;
        m_playerAnimation = new Animation();
        m_playerHeathBar.init(m_pos.x,m_pos.y,200,50);
        m_playerHealth = 100;
        }
        else{
            m_playerCamera.zoom(0.5f);
        }
    }
    /**
     * Konstruktor klasy gracza
     * \param texturePtr wskaznik na texture
     * \param pos pozycja
     * \param size szerkosc
     * \param enginePtr wskaznik na silnik
     * \param gamesave wskaznik na zapis gry
     */
    Player(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size, Engine *enginePtr, int engineDemo, GameSaveData* gamesave)
    {
        m_gameSaveDataPtr = gamesave;
        m_enginePtr = enginePtr;
        m_pos = pos;
        m_size = size;
        m_movestate = NO_INPUT;
        m_pTexture = texturePtr;
        m_velocity = 300.0f;
        m_playerSprite.setTexture(*m_pTexture);
        m_playerSprite.setPosition(m_pos - sf::Vector2f(5, 5));
        m_playerCamera.setCenter(m_pos);
        m_playerCamera.setSize(sf::Vector2f(m_enginePtr->m_window->getSize().x, m_enginePtr->m_window->getSize().y));

        /*// DEBUG
        m_playerShape.setFillColor(sf::Color::Transparent);
        m_playerShape.setOutlineColor(sf::Color::Red);
        m_playerShape.setOutlineThickness(1.0f);*/

        BoxCollider temp(m_pos.x, m_pos.y, m_size.x, m_size.y);
        m_colisionBox = temp;
        enginedemo = engineDemo;

        if (enginedemo == PLAYER_DEMO_TYPE)
        {
            m_playerAnimation = new Animation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }
        else if (enginedemo == PLAYER_BATTLE_TYPE)
        {

            m_animationstate = PLAYER_ANIMATION_IDLE;
            m_playerAnimation = new Animation();
            m_playerHeathBar.init(m_pos.x, m_pos.y, 200, 50);
            m_playerHealth = 100;
        }
        else
        {
            m_playerCamera.zoom(0.5f);
        }
    }
    /**
     * Destruktor klasy gracza
     */
    ~Player(){
        if ((enginedemo == PLAYER_DEMO_TYPE) || (enginedemo == PLAYER_BATTLE_TYPE))
        {
            delete m_playerAnimation;
        }
    }
    /**
     * Metoda aktualizuje gracza
     * \param dt deltatime
     */
    int processEvents(TimeStep dt){

        if(enginedemo == PLAYER_WORLD_MAP_TYPE){
            updatePlayerMap(dt);
        }else if(enginedemo ==PLAYER_BATTLE_TYPE){
            updatePlayerBattle(dt);
        }

        if(enginedemo ==1){
        m_playerAnimation->Update(0, dt);
        m_playerSprite.setTextureRect(m_playerAnimation->m_textureRect);
        }

        return DEFAULT_OBJECT_STATE;
    }
    /**
     * Metoda rysuje gracza
     * \param win_ref referncja do renderu
     */
    void draw(sf::RenderWindow &win_ref){
        win_ref.draw(m_playerSprite);
        //win_ref.draw(m_playerShape);
        if(enginedemo==PLAYER_BATTLE_TYPE){
            m_playerHeathBar.draw(win_ref);
            
        }
    }
    /**
     * Metoda ustawia rozmiar gracza
     * \param size rozmiar
     */
    void setSize(sf::Vector2f size)
    {
        m_size=size;
    }
    /**
     * Metoda ustawia kolor gracza
     * \param color kolor
     */
    void setColor(sf::Color color){
        m_color=color;
    }
    /**
     * Metoda ustawia pozycje gracza
     * \param pos pozycja
     */
    void setPosition(sf::Vector2f pos){
        m_pos=pos;
       
        if(enginedemo!=PLAYER_BATTLE_TYPE){
        m_playerCamera.setCenter(m_pos.x,m_pos.y);
        }
        m_colisionBox.setPos(m_pos);
    }
    /**
     * Metoda ustawia skale gracza
     * \param scale skala
     */
    void setScale(float scale){
        m_scale=scale;
    }

    /**
     * Metoda podaje pozycje gracza
     */
    sf::Vector2f getPos(){
        return m_pos;
    }
    /**
     * Metoda podaje rozmiar gracza
     */
    sf::Vector2f getSize(){
        return m_size;
    }
    /**
     * Metoda podaje kolor gracza
     */
    sf::Color getColor(){
        return m_color;
    }
    /**
     * Metoda podaje skale gracza
     */
    float getScale(){
        return m_scale;
    }
    /**
     * Metoda ustawia teksture gracza
     * \param texrturePtr wskaznik na teksture
     */
    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        m_pTexture = texturePtr;
        m_playerSprite.setTexture(*m_pTexture);
    }
    /**
     * Metoda ustawia stan poruszania sie gracza
     * \param state ustaiwa stan
     */
    void setMoveState(int state)
    {
        m_movestate =state;
    }
    /**
     * Metoda podaje kamere
     */
    sf::View getCamera(){
        return m_playerCamera;
    }
    /**
     * Metoda podaje boxcollider gracza
     */
    BoxCollider &getBoxCollider()
    {
        return m_colisionBox;
    }
    /**
     * Metoda ustawia skale gracza
     * \param scale skala
     */
    void setScaleFactor(sf::Vector2f scale)
    {
        m_scaleFactors = scale;
    }
    /**
     * Metoda ustawia skale gracza
     */
    sf::Vector2f getScaleFactor()
    {
        return m_scaleFactors;
    }
    /**
     * Metoda ustawia zycie gracza
     * \param health zycie
     */
    void setHealth(float health)
    {
        m_playerHealth= health;
        if(m_playerHealth>100){
            m_playerHeathBar.setBackBarSize(m_playerHealth);
        }
    }
    /**
     * Metoda podaje zycie gracza
     */
    float getHealth()
    {
        return m_playerHealth;
    }
    /**
     * Metoda ustawia wartosc ataku gracza
     * \param attack attack
     */
    void setAttack(float attack)
    {
        m_playerAttack =attack;
    }
    /**
     * Metoda podaje wartosc ataku  gracza
     */
    float getAttack()
    {
        return m_playerAttack;
    }
    /**
     * Metoda aktualizuje gracza na mapie
     * \param dt deltatime
     */
    void updatePlayerMap(TimeStep dt)
    {
        if (m_movestate == MOVE_UP)
        {
            m_pos = m_pos + sf::Vector2f(0, -(m_velocity * dt.m_time));
        }
        if (m_movestate == MOVE_DOWN)
        {
            m_pos = m_pos + sf::Vector2f(0, (m_velocity * dt.m_time));
        }
        if (m_movestate == MOVE_LEFT)
        {
            m_pos = m_pos + sf::Vector2f(-(m_velocity * dt.m_time), 0);
        }
        if (m_movestate == MOVE_RIGHT)
        {
            m_pos = m_pos + sf::Vector2f((m_velocity * dt.m_time), 0);
        }
        m_playerShape.setPosition(m_pos);
        m_playerSprite.setPosition(m_pos - sf::Vector2f(5, 5));
        m_colisionBox.setPos(m_pos);
        m_playerShape.setSize(m_size);
        if (m_movestate == MOVE_UP)
        {
            m_playerCamera.move(sf::Vector2f(0, -(m_velocity * dt.m_time)));
        }
        if (m_movestate == MOVE_DOWN)
        {
            m_playerCamera.move(sf::Vector2f(0, (m_velocity * dt.m_time)));
        }
        if (m_movestate == MOVE_LEFT)
        {
            m_playerCamera.move(sf::Vector2f(-(m_velocity * dt.m_time), 0));
        }
        if (m_movestate == MOVE_RIGHT)
        {
            m_playerCamera.move(sf::Vector2f(m_velocity * dt.m_time, 0.0));
        }

        m_enginePtr->m_window->setView(m_playerCamera);
    }
    /**
     * Metoda aktualizuje gracza w bitwie
     * \param dt deltatime
     */
    void updatePlayerBattle(TimeStep dt){

        m_playerAnimation->Update(0, dt);
        m_playerSprite.setTextureRect(m_playerAnimation->m_textureRect);

        m_playerSprite.setScale(-m_scale, m_scale);
        m_playerSprite.setPosition(m_pos - sf::Vector2f(30 * m_scale, 0));
        m_playerSprite.setPosition(m_playerSprite.getPosition().x + m_playerSprite.getGlobalBounds().width - (30 * m_scale/2), m_playerSprite.getPosition().y);

        BoxCollider temp(m_pos.x, m_pos.y, m_size.x * (m_scale), m_size.y * (m_scale));
        m_colisionBox=temp;
        m_colisionBox.setPos(m_pos);

        m_playerShape.setPosition(m_pos);
        m_playerShape.setSize(sf::Vector2f(m_size.x * (m_scale), m_size.y * (m_scale)));
        
        
        float test = m_size.x-100;
        test=test/2;

        m_playerHeathBar.update(m_playerHealth*2,m_pos.x-test,m_pos.y-50);
    }
    /**
     * Metoda ustawia animacje gracza
     * \param state stan animacji
     */
    void setAnimationState(int state)
    {
        m_animationstate = state;
        if (m_animationstate == PLAYER_ANIMATION_ATTACK)
        {
            m_playerAnimation->initAnimation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }
        else if (m_animationstate == PLAYER_ANIMATION_DEATH)
        {
            m_playerAnimation->initAnimation(m_pTexture, sf::Vector2u(10, 1), 0.1f);
        }
        else if (m_animationstate == PLAYER_ANIMATION_IDLE)
        {
            m_playerAnimation->initAnimation(m_pTexture, sf::Vector2u(10, 1), 0.1f);
        }
        else
        {
            m_playerAnimation->initAnimation(m_pTexture, sf::Vector2u(2, 1), 0.1f);
        }
    }
    /**
     * Metoda ustawia doswiadczenie gracza
     * \param e deltatime
     */
    void setExperience(float experience)
    {
        m_playerExperience=experience;
    }
    /**
     * Metoda podaje doswiadczenie gracza
     */
    float getExperience()
    {
        return m_playerExperience;
    }

    public:
    /**
     * Wskaznik na zapis gry
     */
    GameSaveData* m_gameSaveDataPtr;
    int enginedemo;
    /**
     * Wskaznik na animacje
     */
    Animation* m_playerAnimation;
    /**
     * Obiekt RectangleShape
     */
    sf::RectangleShape m_playerShape;
    /**
     * Obiekt sprite
     */
    sf::Sprite m_playerSprite;
    /**
     * velocity
     */
    float  m_velocity;
    /**
     * Obiekt View
     * 
     */
    sf::View m_playerCamera;
    /**
     * Wskaznik na silnik gry
     * 
     */
    Engine* m_enginePtr;
    /**
     * Zmienna przetrzymuje zycie
     */
    float m_playerHealth;
    /**
     * Zmienna przetrzymuje wartosc ataku
     * 
     */
    float m_playerAttack;
    /**
     * Zmienna przetrzymuje wartosc doswiadczenia
     *
     */
    float m_playerExperience;
    /**
     * Obiekt pasku zycia
     *
     */
    HealthBar m_playerHeathBar;
};  

