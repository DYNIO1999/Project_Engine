#pragma once
#include "object.h"
#include "../input/inputtypes.h"
#include "../core/core.h"
#include "../animation/animation.h"
#include "../gui/healthbar.h"

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

class Player :public Object
{
private:

public:
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
    ~Player(){
        if ((enginedemo == PLAYER_DEMO_TYPE) || (enginedemo == PLAYER_BATTLE_TYPE))
        {
            delete m_playerAnimation;
        }
    }
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
    void draw(sf::RenderWindow &win_ref){
        win_ref.draw(m_playerSprite);
        win_ref.draw(m_playerShape);
        if(enginedemo==PLAYER_BATTLE_TYPE){
            m_playerHeathBar.draw(win_ref);
            sf::Sprite test;
            test.setPosition(sf::Vector2f(300,300));
            test.setTexture(*m_pTexture);
            win_ref.draw(test);
        }
    }
    void setSize(sf::Vector2f size)
    {
        m_size=size;
    }
    void setColor(sf::Color color){
        m_color=color;
    }
    void setPosition(sf::Vector2f pos){
        m_pos=pos;
       
        if(enginedemo!=PLAYER_BATTLE_TYPE){
        m_playerCamera.setCenter(m_pos.x,m_pos.y);
        }
        m_colisionBox.setPos(m_pos);
    }
    void setScale(float scale){
        m_scale=scale;
    }


    sf::Vector2f getPos(){
        return m_pos;
    }
    sf::Vector2f getSize(){
        return m_size;
    }
    sf::Color getColor(){
        return m_color;
    }
    float getScale(){
        return m_scale;
    }
    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        m_pTexture = texturePtr;
        m_playerSprite.setTexture(*m_pTexture);
    }
    void setMoveState(int state)
    {
        m_movestate =state;
    }
    sf::View getCamera(){
        return m_playerCamera;
    }
    BoxCollider &getBoxCollider()
    {
        return m_colisionBox;
    }
    void setScaleFactor(sf::Vector2f scale)
    {
        m_scaleFactors = scale;
    }
    sf::Vector2f getScaleFactor()
    {
        return m_scaleFactors;
    }
    void setHealth(float health)
    {
        m_playerHealth= health;
    }
    float getHealth()
    {
        return m_playerHealth;
    }
    void setAttack(float attack)
    {
        m_playerAttack =attack;
    }
    float getAttack()
    {
        return m_playerAttack;
    }

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

    public:
    int enginedemo;
    Animation* m_playerAnimation;
    sf::RectangleShape m_playerShape;
    sf::Sprite m_playerSprite;
    //Animation *m_animation;
    float  m_velocity;
    sf::View m_playerCamera;
    Engine* m_enginePtr;
    float m_playerHealth;
    float m_playerAttack;
    HealthBar m_playerHeathBar;
};  

