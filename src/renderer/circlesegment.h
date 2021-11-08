#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include "point2d.h"
#include "primitivetypes.h"

class CircleSegment
{
public:
    CircleSegment() = default;
    CircleSegment(sf::Vector2i center_point, int radius, int algorithm_index)
    {
        m_center_point.setPointPos(center_point);
        m_radiusX =radius;
        m_choosen_algorithm = algorithm_index;
        InitData();
    
    }
    CircleSegment(sf::Vector2i center_pos, int radiusX, int radiusY, int algorithm_ind)
    {
        m_center_point.setPointPos(center_pos);
        m_radiusX = radiusX;
        m_radiusY = radiusY;
        m_choosen_algorithm = algorithm_ind;
        InitData();
    }

    ~CircleSegment(){
        if(m_choosen_algorithm==CIRCLE_DEFAULT_ALGORITHM){
            if(m_default_circle){
                delete m_default_circle;
            }
        }
    }
    void setPos(sf::Vector2i pos){
        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {
            m_center_point.setPointPos(pos);
            m_default_circle->setPosition(sf::Vector2f(m_center_point.getPointPos()));
        }else{
            m_center_point.setPointPos(pos);
        }
    }
    int getRadX(){
        return m_radiusX;
    }
    void setRadX(int radius){
        m_radiusX= radius;
    }
    int getRadY()
    {
        return m_radiusY;
    }
    void setRadY(int radius)
    {
        m_radiusY = radius;
    }
    sf::Vector2i getPos(){
        return m_center_point.getPointPos();
    }

    void draw(sf::RenderWindow &win_ref, sf::Color color){

        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {            
            m_default_circle->setRadius(m_radiusX);
            m_default_circle->setFillColor(color);
            win_ref.draw(*m_default_circle);
        }else if(m_choosen_algorithm == CIRCLE_SYM4_ALGORITHM){
            DrawCircleSym4Algorithm(win_ref,color);
        }
        else if (m_choosen_algorithm == CIRCLE_SYM8_ALGORITHM)
        {
            DrawCircleSym8Algorithm(win_ref, color);
        }else if(m_choosen_algorithm == ELLIPSE_DEFAULT_ALGORITHM){
            DrawEllipseDefaultAlgo(win_ref,color);
        }
        else if (m_choosen_algorithm ==ELLIPSE_SYM4_ALGORITHM){
            DrawEllipseSym4Algo(win_ref,color);
        }
        else if (m_choosen_algorithm == ELLIPSE_SYM8_ALGORITHM)
        {
            DrawEllipseSym8Algo(win_ref,color);
        }
    }
private:
    void InitData(){
        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {
            m_default_circle = new sf::CircleShape(m_radiusX);
            m_default_circle->setPosition(sf::Vector2f(m_center_point.getPointPos()));
            m_default_circle->setPointCount(100);
        }
    }
    void DrawCircleSym4Algorithm(sf::RenderWindow &win_ref, sf::Color color)
    {
        int x, y, r2;
        m_vertex.color = color;
        r2 = m_radiusX * m_radiusX;
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radiusX;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radiusX;
        win_ref.draw(&m_vertex, 1, sf::Points);
        for(x=1;x<=m_radiusX;x++){
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
        r2 = m_radiusX*m_radiusX;
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radiusX;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radiusX;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x + m_radiusX;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        m_vertex.position.x = m_center_point.getPointPos().x - m_radiusX;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        y = m_radiusX;
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
    void DrawEllipseDefaultAlgo(sf::RenderWindow &win_ref, sf::Color color){
        int i;
        int x, y;
        i =0;
        float endAngle = 360;
        m_vertex.color = color;
        while(i<endAngle){
            x = m_center_point.getPointPos().x + m_radiusX * std::cos(i);
            y = m_center_point.getPointPos().y + m_radiusY * std::sin(i);
            m_vertex.position.x = x;
            m_vertex.position.y = y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            i++;
        }
    }
    void DrawEllipseSym4Algo(sf::RenderWindow &win_ref, sf::Color color)
    {
        /// Zrobic dla y
        m_vertex.color=color;
        int x,y;
        if(m_radiusX>m_radiusY){
        for(x =1; x<=m_radiusX;x++){
            y = (int)(sqrt(((((-1)*(x*x))*(m_radiusY*m_radiusY))+ ((m_radiusX*m_radiusX)*(m_radiusY*m_radiusY)))/(m_radiusX*m_radiusX)));
            m_vertex.position.x = m_center_point.getPointPos().x+x;
            m_vertex.position.y = m_center_point.getPointPos().y+y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x + x;
            m_vertex.position.y = m_center_point.getPointPos().y - y;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x;
            m_vertex.position.y = m_center_point.getPointPos().y + y;
            win_ref.draw(&m_vertex, 1, sf::Points);
        }}else{
            //Dodac dla YYY
        }

    
    }
    void DrawEllipseSym8Algo(sf::RenderWindow &win_ref, sf::Color color)
    {
        int i;
        int x, y;
        i = 0;
        float endAngle = 30;
        m_vertex.color = color;
        while (i < endAngle)
        {
            x = m_center_point.getPointPos().x + m_radiusX * std::cos(i);
            y = m_center_point.getPointPos().y + m_radiusY * std::sin(i);
            m_vertex.position.x = x+0.5;
            m_vertex.position.y = y+0.5;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.color = sf::Color::Blue;
            x = m_center_point.getPointPos().x - m_radiusX * std::cos(i);
            y = m_center_point.getPointPos().y - m_radiusY * std::sin(i);
            m_vertex.position.x = x + 0.5;
            m_vertex.position.y = y + 0.5;
            win_ref.draw(&m_vertex, 1, sf::Points);
            i++;
        }
    }
    sf::CircleShape* m_default_circle;
    sf::Vertex m_vertex;
    Point2D m_center_point;
    int m_radiusX;
    int m_radiusY;
    unsigned int m_choosen_algorithm;
};

