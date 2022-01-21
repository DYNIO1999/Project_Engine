#pragma once
#include "../objects/object.h"
#include "../core/core.h"

/**
 * Klasa Miasto
 */
class Town: public Object
{
private:

public:
    /**
     * @brief Konstrukotr klasy Town
     * 
     * @param texturePtr wsakznik na tekjsture
     * @param pos pozycja
     * @param size szerkosc
     */
    Town(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size)
    {
        m_pTexture = texturePtr;
        m_pos=pos;
        m_size=size;
        m_movestate = NO_INPUT;
        //m_townShape.setPosition(m_pos);
        //m_townShape.setSize(m_size);
        //m_townShape.setFillColor(sf::Color::Transparent);
        //m_townShape.setOutlineThickness(1);
        //m_townShape.setOutlineColor(sf::Color::Magenta);
        m_townSprite.setTexture(*m_pTexture);
        m_townSprite.setPosition(m_pos);
        BoxCollider temp(m_pos.x, m_pos.y, m_size.x, m_size.y);
        m_colisionBox = temp;
    }
    /**
     * Destruktor klasy miasto
     */
    ~Town(){

    }
    
    /**
     * @brief Metoda aktualizujaca 
     * 
     * @param dt deltatime
     * @return int 
     */

    int processEvents(TimeStep dt){
        return DEFAULT_OBJECT_STATE;
    }
    /**
     * @brief Metoda rysujaca
     * 
     * @param win_ref referencja renderu
     */
    void draw(sf::RenderWindow &win_ref){
        //win_ref.draw(m_townShape);
        win_ref.draw(m_townSprite);
    }
    /**
     * @brief Ustawia rozmiar 
     * 
     * @param size rozmiar
     */
    void setSize(sf::Vector2f size)
    {
        m_size = size;
    }
    /**
     * @brief Ustawia kolor
     * 
     * @param color kolor
     */
    void setColor(sf::Color color)
    {
        m_color = color;
    }
    /**
     * @brief ustawia pozycje
     * 
     * @param pos pozycja
     */
    void setPosition(sf::Vector2f pos)
    {
        m_pos = pos;
    }
    /**
     * @brief Ustawia skale
     * 
     * @param scale 
     */
    void setScale(float scale)
    {
        m_scale = scale;
    }
    /**
     * @brief Pobiera pozycje
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f getPos()
    {
        return m_pos;
    }
    /**
     * @brief Pobiera rozmiar
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f getSize()
    {
        return m_size;
    }
    
    /**
     * @brief Pobiera kolor
     * 
     * @return sf::Color 
     */
    sf::Color getColor()
    {
        return m_color;
    }
    /**
     * @brief Pobiera skale
     * 
     * @return float 
     */
    float getScale()
    {
        return m_scale;
    }
    /**
     * @brief Ustawia teksture
     * 
     * @param texturePtr wskaznik na teksture
     */
    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        m_pTexture = texturePtr;
    }
    sf::RectangleShape m_townShape;
    sf::Sprite m_townSprite;
};

