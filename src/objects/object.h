#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Object{
    public:
    virtual ~Object(){}
    virtual void processEvents()=0;
    virtual void draw(sf::RenderWindow &win_ref) = 0;
    virtual void setPosition(float x, float y)=0;
    virtual void setSize(float width, float height)=0;
    virtual void setColor(sf::Color color)=0;
};