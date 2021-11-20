#pragma once 
#include <SFML/Graphics.hpp>
class BoxCollider
{
private:

public:
    BoxCollider(){
        m_left = 0.0f;
        m_top = 0.0f;
        m_width = 0.0f;
        m_height = 0.0f;
    }
    BoxCollider(float left, float top, float width, float height)
    {
        m_left =left;
        m_top =top;
        m_width=width;
        m_height=height;
    }
    ~BoxCollider(){

    }
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
   /* 
    bool will_touch_top(BoxCollider &other, float vel){

    }
    bool will_touch_bottom(BoxCollider &other, float vel){

    }
    bool will_touch_left(BoxCollider &other, float vel){

    }
    bool will_touch_right(BoxCollider &other, float vel){

    }*/
    void move(float x, float y)
    {
        m_left += x;
        m_top += y;
    }
    void move(sf::Vector2f move)
    {
        m_left += move.x;
        m_top += move.y;
    }
    void setPos(sf::Vector2f pos)
    {
        m_left = pos.x;
        m_top = pos.y;
    }
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
    float m_left;
    float m_top;
    float m_width;
    float m_height;
};

