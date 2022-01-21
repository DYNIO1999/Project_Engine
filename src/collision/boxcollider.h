#pragma once 
#include <SFML/Graphics.hpp>
/**
 * Klasa boxcollidera sluzy do kolizji
 */
class BoxCollider
{
private:

public:
    /**
     * Konstruktor klasy boxcollider
     */
    BoxCollider(){
        m_left = 0.0f;
        m_top = 0.0f;
        m_width = 0.0f;
        m_height = 0.0f;
    }
    /**
     * Konstruktor klasy boxcollider
     * \param left lewy rog.
     * \param top lewa gora.
     * \param width szerokosc.
     * \param height wysokosc.
     */
    BoxCollider(float left, float top, float width, float height)
    {
        m_left =left;
        m_top =top;
        m_width=width;
        m_height=height;
    }
    /**
     * Destruktor klasy boxcollider
     */
    ~BoxCollider(){

    }
    /**
     * Metoda sprawdzajaca czy dwa obiekty nachodza na siebie
     * \param other inny boxcollider.
     */
    bool intersects(BoxCollider& other){
        float bot = m_top + m_height;
        float right = m_left + m_width;
        float otherbot = other.m_top + other.m_height;
        float otherright = other.m_left + other.m_width;
        bool notColliding = bot < other.m_top || m_top > otherbot || m_left > otherright || right < other.m_left;

        if (notColliding == false)
        {
            return true;
        }
        else
        {
            return false;
        }
        return notColliding == false;
    }
    /**
     * Metoda sprawdzajaca czy dany punkt znajduje sie w boxcolliderze
     * \param other punkt o wspolrzednych.
     */
    bool contains(sf::Vector2f other)
    {
        float bot = m_top + m_height - 1;
        float right = m_left + m_width - 1;
        return (m_left <= other.x && other.x <= right) && (m_top <= other.y && other.y <= bot);
    }

    /**
     * Meotda przesuwajaca boxcollider
     * \param x w osi x.
     * \param y w osi y.
     */
    void move(float x, float y)
    {
        m_left += x;
        m_top += y;
    }
    /**
     * Meotda przesuwajaca boxcollider
     * \param move vector w osi x i y.
     */
    void move(sf::Vector2f move)
    {
        m_left += move.x;
        m_top += move.y;
    }
    /**
     * Meotda ustawiajaca pozycje
     *  \param pos vector pozycja x i y.
     */
    void setPos(sf::Vector2f pos)
    {
        m_left = pos.x;
        m_top = pos.y;
    }
    /**
     * Meotda odpowiadajaca na kolizje
     *  \param other inny boxcollider.
     */
    sf::Vector2f resolve_collision_rect(BoxCollider &other){

        if(!intersects(other)){
            return sf::Vector2f(0,0);
        }
        float bot = m_top + m_height;
        float right = m_left + m_width;
        float otherbot = other.m_top + other.m_height;
        float otherright = other.m_left + other.m_width;
        //Distances
        float toTop = other.m_top - bot;
        float toBot = otherbot - m_top;
        float toLeft = other.m_left - right;
        float toRight = otherright - m_left;

        float min = std::min({std::abs(toTop), std::abs(toBot), std::abs(toLeft), std::abs(toRight)});
        if (std::abs(toTop) == min)
        {
            return sf::Vector2f(0.f, toTop);
        }
        else if (std::abs(toBot) == min)
        {
            return sf::Vector2f(0.f, toBot);
        }
        else if (std::abs(toLeft) == min)
        {
            return sf::Vector2f(toLeft, 0.f);
        }
        else
        {
            return sf::Vector2f(toRight, 0.f);
        }
    }
    /**
     * lewa gora
     */
    float m_left;
    /**
     * lewa gora
     */
    float m_top;
    /**
     * szerokosc
     */
    float m_width;
    /**
     * wysokosc
     */
    float m_height;
};

