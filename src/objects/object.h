#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Object{
    public:
    
    Object(){}
    virtual ~Object(){}

    virtual void processEvents()=0;
    virtual void draw(sf::RenderWindow &win_ref) = 0;
    
    virtual void setSize(sf::Vector2f size)=0;
    virtual void setColor(sf::Color color)=0;
    virtual void setPosition(sf::Vector2f pos)=0;
    virtual void setScale(float scale)=0;


    virtual sf::Vector2f getPos()=0;
    virtual sf::Vector2f getSize()=0;
    virtual sf::Color getColor()=0;
    virtual float getScale() = 0;
    virtual void setTexture(sf::Texture* texture)=0;
    
    protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_size;
    sf::Color m_color;
    float m_scale;
    sf::Texture *m_curTexture;
    sf::Sprite *m_curSprite;
};