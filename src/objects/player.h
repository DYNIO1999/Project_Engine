#pragma once
#include "object.h"
#include "../input/inputtypes.h"
#include "../core/core.h"
#include "../animation/animation.h"

/**  
* Klasa gracza
*/
class Player :public Object
{
private:

public:
    Player(std::shared_ptr<sf::Texture> texturePtr,sf::Vector2f pos, sf::Vector2f size, Engine* enginePtr, int engineDemo){
        m_enginePtr = enginePtr;
        m_pos =sf::Vector2f((((float)m_enginePtr->m_window->getSize().x) / 2.0), ((float)m_enginePtr->m_window->getSize().y) / 2.0);
        m_size = size;
        m_movestate = NO_INPUT;
        m_pTexture=texturePtr;
        m_velocity = 300.0f;
        m_playerShape.setPosition(m_pos);
        m_playerShape.setSize(m_size);
        m_playerShape.setFillColor(sf::Color::Transparent);
        m_playerShape.setOutlineThickness(2);
        m_playerShape.setOutlineColor(sf::Color::Magenta);
        m_playerSprite.setTexture(*m_pTexture);
        m_playerSprite.setPosition(m_pos- sf::Vector2f(50, 10));
        m_playerCamera.setCenter(sf::Vector2f((((float)m_enginePtr->m_window->getSize().x) / 2.0), ((float)m_enginePtr->m_window->getSize().y) / 2.0));
        m_playerCamera.setSize(sf::Vector2f(m_enginePtr->m_window->getSize().x, m_enginePtr->m_window->getSize().y));
        
        BoxCollider temp(m_pos.x,m_pos.y,m_size.x,m_size.y);
        m_colisionBox = temp;
        enginedemo = engineDemo;
        if(enginedemo==1){
        m_playerAnimation = new Animation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }else{
            m_playerCamera.zoom(0.5f);
        }
    }
    ~Player(){
        if(enginedemo==1){
        delete m_playerAnimation;
        }

    }
    int processEvents(TimeStep dt){
        if(m_movestate == MOVE_UP){
            m_pos=m_pos+sf::Vector2f(0,-(m_velocity*dt.m_time));
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
        //m_playerShape.setPosition(m_pos);
        m_playerSprite.setPosition(m_pos-sf::Vector2f(50,10));
        m_colisionBox.setPos(m_pos);
        //m_playerShape.setSize(m_size);
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
        if(enginedemo ==1){
        m_playerAnimation->Update(0, dt);
        m_playerSprite.setTextureRect(m_playerAnimation->m_textureRect);
        }
        return DEFAULT_OBJECT_STATE;
    }
    void draw(sf::RenderWindow &win_ref){
        win_ref.draw(m_playerSprite);
        //win_ref.draw(m_playerShape);
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
        m_playerCamera.setCenter(m_pos.x,m_pos.y);
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
    public:
    int enginedemo;
    Animation* m_playerAnimation;
    sf::RectangleShape m_playerShape;
    sf::Sprite m_playerSprite;
    //Animation *m_animation;
    float  m_velocity;
    sf::View m_playerCamera;
    Engine* m_enginePtr;
};

