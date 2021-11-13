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
        m_thickness = 1;
        InitData();
    
    }
    CircleSegment(sf::Vector2i center_pos, int radiusX, int radiusY, int algorithm_index)
    {
        m_center_point.setPointPos(center_pos);
        m_radiusX = radiusX;
        m_radiusY = radiusY;
        m_choosen_algorithm = algorithm_index;
        m_thickness = 1;
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
    void setFillColor(sf::Color fillcolor){
        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {
            m_default_circle->setFillColor(fillcolor);
        }
    }

    void draw(sf::RenderWindow &win_ref, sf::Color color){

        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {            
            m_default_circle->setRadius(m_radiusX);
            m_default_circle->setOutlineColor(color);
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
    }
    int getThickness(){
        return m_thickness;
    }
    void setThickness(int thickness){
        if(thickness>0){
            m_thickness = thickness;
        }
    }
private:
    void InitData(){
        if (m_choosen_algorithm == CIRCLE_DEFAULT_ALGORITHM)
        {
            m_default_circle = new sf::CircleShape(m_radiusX);
            m_default_circle->setPosition(sf::Vector2f(m_center_point.getPointPos()));
            m_default_circle->setPointCount(100);
            m_default_circle->setOutlineThickness(float(m_thickness));
        }
    }
    void DrawCircleSym4Algorithm(sf::RenderWindow &win_ref, sf::Color color)
    {
        int x, y, r2;
        m_vertex.color = color;
        r2 = m_radiusX * m_radiusX;
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radiusX+k;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radiusX-k;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        for(x=1;x<=m_radiusX;x++){
            y = (int)sqrt(r2-(x*x)+0.5);
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y + y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y +y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
        }
    }
    void DrawCircleSym8Algorithm(sf::RenderWindow &win_ref, sf::Color color){
        int x , y ,r2;
        m_vertex.color = color;
        r2 = m_radiusX*m_radiusX;
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y + m_radiusX+k;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x;
        m_vertex.position.y = m_center_point.getPointPos().y - m_radiusX-k;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x + m_radiusX+k;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        for (int k = 0; k < m_thickness; k++){
        m_vertex.position.x = m_center_point.getPointPos().x - m_radiusX-k;
        m_vertex.position.y = m_center_point.getPointPos().y;
        win_ref.draw(&m_vertex, 1, sf::Points);
        }
        y = m_radiusX;
        x =1;
        y =(int)(sqrt(r2-1+0.5));
        while(x<y){
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x+x+k;
            m_vertex.position.y = m_center_point.getPointPos().y+y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x  - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y + y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().y + y+k;
            m_vertex.position.y = m_center_point.getPointPos().x + x+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().y + y+k;
            m_vertex.position.y = m_center_point.getPointPos().x - x-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().y - y-k;
            m_vertex.position.y = m_center_point.getPointPos().x + x+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().y - y-k;
            m_vertex.position.y = m_center_point.getPointPos().x - x-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            x=x+1;
            y = (int)(sqrt(r2-(x*x)+0.5));
        }
        if(x==y){
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y + y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y + y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
            for (int k = 0; k < m_thickness; k++){
            m_vertex.position.x = m_center_point.getPointPos().x - x-k;
            m_vertex.position.y = m_center_point.getPointPos().y - y-k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
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
            for (int k = 0; k < m_thickness; k++)
            {
                m_vertex.position.x = x+k;
                m_vertex.position.y = y+k;
                win_ref.draw(&m_vertex, 1, sf::Points);
            }
            i++;
        }
    }
    void DrawEllipseSym4Algo(sf::RenderWindow &win_ref, sf::Color color)
    {
        m_vertex.color=color;
        int x,y;
        for(x =1; x<=m_radiusX;x++){
            y = (int)(sqrt(((((-1)*(x*x))*(m_radiusY*m_radiusY))+ ((m_radiusX*m_radiusX)*(m_radiusY*m_radiusY)))/(m_radiusX*m_radiusX)));
            for(int k=0;k<m_thickness;k++){
            m_vertex.position.x = m_center_point.getPointPos().x+x+k;
            m_vertex.position.y = m_center_point.getPointPos().y+y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x+k;
            m_vertex.position.y = m_center_point.getPointPos().y - y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x + x+k;
            m_vertex.position.y = m_center_point.getPointPos().y - y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            m_vertex.position.x = m_center_point.getPointPos().x - x+k;
            m_vertex.position.y = m_center_point.getPointPos().y + y+k;
            win_ref.draw(&m_vertex, 1, sf::Points);
            }
        }
    }
    sf::CircleShape* m_default_circle;
    sf::Vertex m_vertex;
    Point2D m_center_point;
    int m_radiusX;
    int m_radiusY;
    unsigned int m_choosen_algorithm;
    int m_thickness;
};

