#pragma once
#include <SFML/Graphics.hpp>
class Point2D
{
private:

public:    
    Point2D(){
        
    }
    Point2D(sf::Vector2i pos)
    {
        m_pos=pos;
    }
    ~Point2D(){

    }
    sf::Vector2i getPointPos(){
        return m_pos;
    }
    void setPointPos(sf::Vector2i pos){
        m_pos=pos;
    }
    void setPosX(int x){
        m_pos.x=x;
    }
    void setPosY(int y){
        m_pos.y=y;
    }
    private:
    sf::Vector2i m_pos;
};

