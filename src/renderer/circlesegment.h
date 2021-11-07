#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "point2d.h"
#include "primitivetypes.h"

class CircleSegment
{
public:
    CircleSegment(sf::Vector2i center_point, int radius, int algorithm_index = CIRCLE_SIMPLE_ALGORITHM)
    {
        m_center_point.setPointPos(center_point);
        m_radius =radius;
        m_choosen_algorithm = algorithm_index;
        InitData();
    
    }

    ~CircleSegment(){
        if(m_choosen_algorithm==CIRCLE_SIMPLE_ALGORITHM){
            if(m_default_circle){
                delete m_default_circle;
            }
        }
    }
    void setPos(sf::Vector2i pos){
        if (m_choosen_algorithm == CIRCLE_SIMPLE_ALGORITHM){
            m_center_point.setPointPos(pos);
            m_default_circle->setPosition(sf::Vector2f(m_center_point.getPointPos()));
        }
    }
    int getRadius(){
        return m_radius;
    }
    void setRadius(int radius){
        m_radius= radius;
    }
    sf::Vector2i getPos(){
        return m_center_point.getPointPos();
    }

    void draw(sf::RenderWindow &win_ref, sf::Color color){
        
        if (m_choosen_algorithm == CIRCLE_SIMPLE_ALGORITHM)
        {            
            m_default_circle->setRadius(m_radius);
            m_default_circle->setFillColor(color);
            win_ref.draw(*m_default_circle);
        }else if(m_choosen_algorithm == CIRCLE_SYM4_ALGORITHM){
            DrawCircleSym4Algorithm(win_ref,color);
        }
        else if (m_choosen_algorithm == CIRCLE_SYM8_ALGORITHM)
        {
            DrawCircleSym8Algorithm(win_ref, color);
        }
    }
private:
    void InitData(){
        if (m_choosen_algorithm==CIRCLE_SIMPLE_ALGORITHM){
            m_default_circle = new sf::CircleShape(m_radius);
            m_default_circle->setPosition(sf::Vector2f(m_center_point.getPointPos()));
            m_default_circle->setPointCount(100);
        }
    }
    void DrawCircleSym4Algorithm(sf::RenderWindow &win_ref, sf::Color color)
    {
        int x, y, r2;
        m_vertex.color = color;
        r2 = m_radius * m_radius;
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radius;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radius;
        win_ref.draw(&m_vertex, 1, sf::Points);
        for(x=1;x<=m_radius;x++){
            y = (int)sqrt(r2-(x*x)+0.5);
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y + y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x -x;
            m_vertex.position.y = m_center_point.getPointPos().y +y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x -x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
        }
    }
    void DrawCircleSym8Algorithm(sf::RenderWindow &win_ref, sf::Color color){
        int x , y ,r2;
        m_vertex.color = color;
        r2 = m_radius*m_radius;
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radius;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radius;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x + m_radius;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x - m_radius;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        y = m_radius;
        x =1;
        y =(int)(sqrt(r2-1+0.5));
        while(x<y){
            m_vertex.position.x = m_center_point.getPointPos().x+x;
            m_vertex.position.y = m_center_point.getPointPos().y+y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x  - x;
            m_vertex.position.y = m_center_point.getPointPos().y + y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().y + y;
            m_vertex.position.y = m_center_point.getPointPos().x + x;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().y + y;
            m_vertex.position.y = m_center_point.getPointPos().x - x;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().y - y;
            m_vertex.position.y = m_center_point.getPointPos().x + x;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().y - y;
            m_vertex.position.y = m_center_point.getPointPos().x - x;
            win_ref.draw(&m_vertex, 1, sf::Points);
            x=x+1;
            y = (int)(sqrt(r2-(x*x)+0.5));
        }
        if(x==y){
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y + y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x;
            m_vertex.position.y = m_center_point.getPointPos().y + y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
        }
    }
    sf::CircleShape* m_default_circle;
    sf::Vertex m_vertex;
    Point2D m_center_point;
    int m_radius;
    unsigned int m_choosen_algorithm;
};

