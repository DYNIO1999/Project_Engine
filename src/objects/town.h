#pragma once
#include "../objects/object.h"
#include "../core/core.h"

class Town: public Object
{
private:

public:
    Town(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size)
    {
        m_pTexture = texturePtr;
        m_pos=pos;
        m_size=size;
        m_movestate = NO_INPUT;
        m_townShape.setPosition(m_pos);
        m_townShape.setSize(m_size);
        m_townShape.setFillColor(sf::Color::Transparent);
        //m_playerShape.setTexture(&(*m_pTexture));
        m_townShape.setOutlineThickness(2);
        m_townShape.setOutlineColor(sf::Color::Magenta);
        m_townSprite.setTexture(*m_pTexture);
        m_townSprite.setPosition(m_pos);
    }
    ~Town(){

    }
    int processEvents(TimeStep dt){
        return DEFAULT_OBJECT_STATE;
    }
    void draw(sf::RenderWindow &win_ref){
        win_ref.draw(m_townShape);
        win_ref.draw(m_townSprite);
    }
    void setSize(sf::Vector2f size)
    {
        m_size = size;
    }
    void setColor(sf::Color color)
    {
        m_color = color;
    }
    void setPosition(sf::Vector2f pos)
    {
        m_pos = pos;
    }
    void setScale(float scale)
    {
        m_scale = scale;
    }

    sf::Vector2f getPos()
    {
        return m_pos;
    }
    sf::Vector2f getSize()
    {
        return m_size;
    }
    sf::Color getColor()
    {
        return m_color;
    }
    float getScale()
    {
        return m_scale;
    }
    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        m_pTexture = texturePtr;
    }
    sf::RectangleShape m_townShape;
    sf::Sprite m_townSprite;
};

