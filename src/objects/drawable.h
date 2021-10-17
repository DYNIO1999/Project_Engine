#pragma once
//#include <vector>
#include "static_object.h"


enum PRIMITIVE_TYPE
{
    SQAURE,
    RECTANGLE,
    TRIANGLE =3,
};

class Drawable : public Static_Object 
{
public:
    Drawable(int primitivetype, int pos_x, int pos_y, int width, int height, sf::Color color)
    {
        this->m_primitivetype = primitivetype;
        this->x=pos_x;
        this->y=pos_y;
        this->m_width = width;
        this->m_height = height;
        this->m_color = color;
        //this->m_vertices_count=count;
        initPrimitive();
    }
    ~Drawable() {
        delete[] m_vertices;
    }
    void processEvents() override{

    }
    void draw(sf::RenderWindow& win_ref) override{
        if (m_primitivetype == RECTANGLE){
            win_ref.draw(m_vertices,4 , sf::Quads);
       }
        if(m_primitivetype == TRIANGLE){
            win_ref.draw(m_vertices, 3, sf::Triangles);
        }

    }
    void initPrimitive(){
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices = new sf::Vertex[4];
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;
            
            m_vertices[1].position.x = x+m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x+m_width;
            m_vertices[2].position.y = y+m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y+m_height;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }
        if(m_primitivetype == TRIANGLE){
            m_vertices = new sf::Vertex[3];
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x+(m_width/2);
            m_vertices[1].position.y = y+m_height;

            m_vertices[2].position.x = x-(m_width/2);
            m_vertices[2].position.y = y + m_height;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
        }
    }
    void setPosition(float x, float y){
        if (m_primitivetype == RECTANGLE){
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x + m_width;
            m_vertices[2].position.y = y + m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y + m_height;
        }
        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + (m_width / 2);
            m_vertices[1].position.y = y + m_height;

            m_vertices[2].position.x = x - (m_width / 2);
            m_vertices[2].position.y = y + m_height;
        }

    }
    void setColor(sf::Color color){
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }

        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].color = color;
            m_vertices[1].color = color;
            m_vertices[2].color = color;
        }
    }
    void setSize(float width, float height){
        m_width=width;
        m_height=height;
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x + m_width;
            m_vertices[2].position.y = y + m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y + m_height;
        }
        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + (m_width / 2);
            m_vertices[1].position.y = y + m_height;

            m_vertices[2].position.x = x - (m_width / 2);
            m_vertices[2].position.y = y + m_height;
        }
    }

    int m_primitivetype;
    int m_vertices_count;
    sf::Vertex* m_vertices;
    sf::Color m_color;

private:
};