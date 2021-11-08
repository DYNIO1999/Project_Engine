#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Zastanowic sie czy to ma sens

class Object{
    public:
    
    Object(){}
    virtual ~Object(){}

    virtual void processEvents(){

    }
    
    virtual void processEvents(TimeStep dt)
    {
    }
    virtual void draw(sf::RenderWindow &win_ref) = 0;
    
    
    virtual void setSize(sf::Vector2f size)=0;
    virtual void setColor(sf::Color color)=0;
    virtual void setPosition(sf::Vector2f pos)=0;
    
    virtual void setScale(float scale){

    }
    virtual sf::Vector2f getPos()=0;
    virtual sf::Vector2f getSize()=0;
    virtual sf::Color getColor()=0;
    virtual void setPosition(sf::Vector2f start_pos, sf::Vector2f end_pos){

    }
    virtual sf::Vector2f getPosStartPoint(){
        return m_pos;
    }
    virtual sf::Vector2f getPosEndPoint(){
        return m_size;
    }
    virtual float getScale(){
        return m_scale;
    }

    virtual int getType(){
        return m_type;
    }
    virtual void setRadiusX(int radius){
    }
    virtual void setRadiusY(int radius){

    }
    virtual int getRadiusX(){
        return 0;
    }
    virtual int getRadiusY()
    {
        return 0;
    }
    protected:
    int m_type;
    sf::Vector2f m_pos;
    sf::Vector2f m_size;
    sf::Color m_color;
    float m_scale;
    sf::Texture *m_curTexture;
    sf::Sprite *m_curSprite;
};