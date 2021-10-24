#pragma once
#include "object.h"

//DYNIEK TEN KOD TRZEBA POTEM PRZENIESC DO .CPP TY IDIOTO!

class Primitive: public  Object
{

public:
    Primitive(int type, sf::Vector2f pos, sf::Vector2f size, sf::Color color){
        m_type =type;
        m_pos =pos;
        m_size =size;
        m_color =color;
        if (m_type==PRIMITIVE_TRIANGLE){
            m_vertices = new sf::Vertex[3];
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + (m_size.x / 2);
            m_vertices[1].position.y = m_pos.y + m_size.y;

            m_vertices[2].position.x = m_pos.x - (m_size.x / 2);
            m_vertices[2].position.y = m_pos.y + m_size.y;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
        }
        if (m_type == PRIMITIVE_QUAD)
        {
            m_vertices = new sf::Vertex[4];
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + m_size.x;
            m_vertices[1].position.y = m_pos.y;

            m_vertices[2].position.x = m_pos.x + m_size.x;
            m_vertices[2].position.y = m_pos.y + m_size.y;

            m_vertices[3].position.x = m_pos.x;
            m_vertices[3].position.y = m_pos.y + m_size.y;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }
        if (m_type == PRIMITIVE_CIRCLE)
        {
            m_circle = new sf::CircleShape(m_size.x);
            m_circle->setPosition(m_pos.x, m_pos.y);
            m_circle->setFillColor(m_color);
        }
    }
    /*Primitive(int type, sf::Vector2f pos, sf::Vector2f size, sf::Color color)
    {
        m_type =type;
        m_pos = pos;
        m_size = size;
        m_color = color;
        if (m_type == PRIMITIVE_TRIANGLE)
        {
        
        }
        if (m_type == PRIMITIVE_QUAD)
        {
            m_vertices = new sf::Vertex[4];
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + m_size.x;
            m_vertices[1].position.y = m_pos.y;

            m_vertices[2].position.x = m_pos.x + m_size.x;
            m_vertices[2].position.y = m_pos.y + m_size.y;

            m_vertices[3].position.x = m_pos.x;
            m_vertices[3].position.y = m_pos.y + m_size.y;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }
    }*/
    ~Primitive(){
        std::cout<<"PRIMITIVE TYPE: "<<m_type<<'\n';
        if(m_type==PRIMITIVE_CIRCLE){
            delete m_circle;
        }else{
            delete[] m_vertices;
        }
    }
    void draw(sf::RenderWindow &win_ref){
        if (m_type == PRIMITIVE_TRIANGLE)
        {
            win_ref.draw(m_vertices, 3, sf::Triangles);
        }
        if(m_type == PRIMITIVE_QUAD){
            win_ref.draw(m_vertices, 4, sf::Quads);
        }
        if (m_type == PRIMITIVE_CIRCLE)
        {
            win_ref.draw(*m_circle);
        }
    } 
    void setSize(sf::Vector2f size){
        m_size = size;
        if (m_type == PRIMITIVE_TRIANGLE)
        {
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + (m_size.x / 2);
            m_vertices[1].position.y = m_pos.y + m_size.y;

            m_vertices[2].position.x = m_pos.x - (m_size.x / 2);
            m_vertices[2].position.y = m_pos.y + m_size.y;
        }
        if (m_type == PRIMITIVE_QUAD)
        {
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + m_size.x;
            m_vertices[1].position.y = m_pos.y;

            m_vertices[2].position.x = m_pos.x + m_size.x;
            m_vertices[2].position.y = m_pos.y + m_size.y;

            m_vertices[3].position.x = m_pos.x;
            m_vertices[3].position.y = m_pos.y + m_size.y;
        }
        if (m_type == PRIMITIVE_CIRCLE)
        {
            m_circle->setRadius(m_size.x);
        }
    }
    void setColor(sf::Color color){
        m_color=color;
        if (m_type == PRIMITIVE_TRIANGLE)
        {
            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
        }
        if (m_type == PRIMITIVE_QUAD)
        {
            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }
        if (m_type == PRIMITIVE_CIRCLE)
        {
            m_circle->setFillColor(m_color);
        }
    }
    void setPosition(sf::Vector2f pos){
        m_pos=pos;
        if (m_type == PRIMITIVE_TRIANGLE)
        {
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + (m_size.x / 2);
            m_vertices[1].position.y = m_pos.y + m_size.y;

            m_vertices[2].position.x = m_pos.x - (m_size.x / 2);
            m_vertices[2].position.y = m_pos.y + m_size.y;
        }
        if (m_type == PRIMITIVE_QUAD)
        {
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;

            m_vertices[1].position.x = m_pos.x + m_size.x;
            m_vertices[1].position.y = m_pos.y;

            m_vertices[2].position.x = m_pos.x + m_size.x;
            m_vertices[2].position.y = m_pos.y + m_size.y;

            m_vertices[3].position.x = m_pos.x;
            m_vertices[3].position.y = m_pos.y + m_size.y;
        }
        if (m_type == PRIMITIVE_CIRCLE)
        {
            m_circle->setPosition(m_pos.x, m_pos.y);
        }
    }
    int getType(){
        return m_type;
    }
    sf::Vector2f getPos(){
        return m_pos;
    }
    sf::Vector2f getSize(){
        return m_size;
    }
    sf::Color getColor(){
        return m_color;
    }
    private:
    sf::CircleShape* m_circle;
    sf::Vertex *m_vertices;
};


