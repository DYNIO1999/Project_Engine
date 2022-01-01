#pragma once
#include "../core/core.h"
#include "../collision/boxcollider.h"

class Potion
{
private:
    float m_boostHealth;
    BoxCollider m_colisionBox;
    sf::Sprite m_potionSprite;
    std::shared_ptr<sf::Texture> m_pTexture;
    sf::RectangleShape m_potionShape;

public:
    Potion(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size, Engine *enginePtr, float boosthealth)
    {   
        m_boostHealth=boosthealth;
        m_pTexture =texturePtr;

        m_potionSprite.setTexture(*m_pTexture);
        m_potionSprite.setPosition(pos);


        BoxCollider temp(pos.x,pos.y,size.x,size.y);
        m_colisionBox = temp;

        m_potionShape.setFillColor(sf::Color::Transparent);
        m_potionShape.setOutlineColor(sf::Color::Red);
        m_potionShape.setOutlineThickness(1.0f);
        m_potionShape.setSize(size);
        m_potionShape.setPosition(pos);

    }
    ~Potion(){

    }
    BoxCollider& getBoxCollider(){
        return m_colisionBox;
    }
    void update(){

    }
    void draw(sf::RenderWindow &win_ref)
    {
        win_ref.draw(m_potionSprite);
        win_ref.draw(m_potionShape);
    }
};


