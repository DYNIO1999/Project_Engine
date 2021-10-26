#pragma once
#include "point2d.h"
class LineSegment
{
public:
    LineSegment(sf::Vector2i start_point, sf::Vector2i end_point, int count_lines){
        m_points[0].setPointPos(start_point);
        m_points[1].setPointPos(end_point);
        m_count_lines=count_lines;
        flipX =false;
        flipY =false;
    }
    ~LineSegment(){

    }
    void draw(sf::RenderWindow& win_ref, sf::Color color)
    {
        m_vertex.color =color;
        /*if(flipX){
            int temp;
            temp = m_points[0].getPointPos().x;
            m_points[0].setPosX(m_points[1].getPointPos().x);
            m_points[1].setPosX(temp);
            flipX =false;
        }
        if(flipY){
            int temp;
            temp = m_points[0].getPointPos().y;
            m_points[0].setPosY(m_points[1].getPointPos().y);
            m_points[1].setPosY(temp);
            flipY = false;
        }
    
        if (m_points[1].getPointPos().x < m_points[0].getPointPos().x)
        {
            int temp;
            temp = m_points[0].getPointPos().x;
            m_points[0].setPosX(m_points[1].getPointPos().x);
            m_points[1].setPosX(temp);
            std::cout << "Changing X" << '\n';
            flipX=true;
        }
        if (m_points[1].getPointPos().y < m_points[0].getPointPos().y)
        {
            int temp;
            temp = m_points[0].getPointPos().y;
            m_points[0].setPosY(m_points[1].getPointPos().y);
            m_points[1].setPosY(temp);
            std::cout << "Changing Y" << '\n';
            flipY=true;
        }*/
        float dx = m_points[1].getPointPos().x - m_points[0].getPointPos().x;
        float dy = m_points[1].getPointPos().y - m_points[0].getPointPos().y;
        float m = dy/dx;
        if(m<0){
            m=m*(-1);
        }
        std::cout << "M1" << m << '\n';
        if(m<=1){
        float y;
        int x;
        y= m_points[0].getPointPos().y;
        if (m_points[1].getPointPos().x < m_points[0].getPointPos().x){
            for (x = m_points[1].getPointPos().x; x <= m_points[0].getPointPos().x; x++)
            {
                m_vertex.position.x = x;
                m_vertex.position.y = y + 0.5;
                win_ref.draw(&m_vertex, 1, sf::Points);
                y = y + m;
            }
        }else{
            for (x = m_points[0].getPointPos().x; x <= m_points[1].getPointPos().x; x++)
            {
                m_vertex.position.x = x;
                m_vertex.position.y = y + 0.5;
                win_ref.draw(&m_vertex, 1, sf::Points);
                y = y + m;
            }
        }
        }else{
            float x;
            int y;
            dx = m_points[1].getPointPos().x - m_points[0].getPointPos().x;
            dy = m_points[1].getPointPos().y - m_points[0].getPointPos().y;
            m = dx / dy;
            x = m_points[0].getPointPos().x;
            std::cout << "M2" << m << '\n';
            if (m_points[1].getPointPos().y < m_points[0].getPointPos().y){
                for (y = m_points[1].getPointPos().y; y <= m_points[0].getPointPos().y; y++)
                {
                    m_vertex.position.x = x + 0.5;
                    m_vertex.position.y = y;
                    win_ref.draw(&m_vertex, 1, sf::Points);
                    x = x + m;
                }
            }else{
            for (y = m_points[0].getPointPos().y; y <= m_points[1].getPointPos().y; y++)
            {
                m_vertex.position.x = x + 0.5;
                m_vertex.position.y = y;
                win_ref.draw(&m_vertex, 1, sf::Points);
                x = x + m;
            }
            }
        }
    }
    /*void drawLineNaive(int x0, int y0, int x1, int y1){
        float dx = x1-x0;
        float dy = y1-y0;
        float m 
    }*/
    int m_count_lines;
    sf::Vertex m_vertex;
    Point2D m_points[2];
    bool flipX;
    bool flipY;
};


