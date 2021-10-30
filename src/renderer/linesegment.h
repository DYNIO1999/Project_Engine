#pragma once
#include "point2d.h"
enum DRAW_LINE
{
    LINE_DEFAULT_ALGORITHM,
    LINE_NAIVE_ALGORITHM,
    LINE_BRESENHAM_ALGORITHM,
    LINE_WU_ALGORITHM,
};
class LineSegment
{
public:
    LineSegment(sf::Vector2i start_point, sf::Vector2i end_point, int count_lines, int algorithm_index = LINE_DEFAULT_ALGORITHM)
    {
        m_points[0].setPointPos(start_point);
        m_points[1].setPointPos(end_point);
        m_count_lines = count_lines;
        flipX = false;
        flipY = false;
        m_choosen_algorithem = algorithm_index;
    }
    ~LineSegment()
    {
    }
    void draw(sf::RenderWindow &win_ref, sf::Color color)
    {
        m_vertex.color = color;
        if (m_choosen_algorithem == LINE_DEFAULT_ALGORITHM)
        {
            std::cout << "DRAW LINE DEFAULT\n";
        }
        else if (m_choosen_algorithem == LINE_NAIVE_ALGORITHM)
        {
            drawLineNaive(win_ref);
        }
    }
    void setPos(sf::Vector2i start_point, sf::Vector2i end_point)
    {
        if((start_point.x>=end_point.x)&&(start_point.y>=end_point.y)){
            m_points[0].setPointPos(end_point);
            m_points[1].setPointPos(start_point);
            std::cout<<"Change"<<'\n';
        }else{
        m_points[0].setPointPos(start_point);
        m_points[1].setPointPos(end_point);
    }        
    }

private:
    void drawLineNaive(sf::RenderWindow &win_ref)
    {
        float dx = m_points[1].getPointPos().x - m_points[0].getPointPos().x;
        float dy = m_points[1].getPointPos().y - m_points[0].getPointPos().y;
        float m = dy / dx;
        if(m<0){
            m=(m*(-1));
        }
        if (((m < 1) && (dx!=0)))
        {
            float y;
            int x;
            y = m_points[0].getPointPos().y;

                if ((m_points[1].getPointPos().x <= m_points[0].getPointPos().x) && (m_points[1].getPointPos().y >= m_points[0].getPointPos().y)){
                    std::cout << "CHECK 1" << '\n';
                    for (x = m_points[0].getPointPos().x; x >= m_points[1].getPointPos().x; x--)
                    {
                        m_vertex.position.x = x;
                        m_vertex.position.y = y + 0.5;
                        win_ref.draw(&m_vertex, 1, sf::Points);
                        y = y + m;
                    }
                }else{
                    std::cout << "CHECK 2" << '\n';
                    for (x = m_points[0].getPointPos().x; x <= m_points[1].getPointPos().x; x++)
                    {
                        m_vertex.position.x = x;
                        m_vertex.position.y = y + 0.5;
                        win_ref.draw(&m_vertex, 1, sf::Points);
                        y = y + m;
                    }
                }

        }
        else
        {
            float x;
            int y;
            dx = m_points[1].getPointPos().x - m_points[0].getPointPos().x;
            dy = m_points[1].getPointPos().y - m_points[0].getPointPos().y;
            m = dx / dy;
            if (m < 0)
            {
                m = (m * (-1));
            }
            x = m_points[0].getPointPos().x;

            if ((m_points[1].getPointPos().x <= m_points[0].getPointPos().x) && (m_points[1].getPointPos().y >= m_points[0].getPointPos().y))
            {
                std::cout << "CHECK 3" << '\n';
                for (y = m_points[0].getPointPos().y; y <= m_points[1].getPointPos().y; y++)
                {
                    m_vertex.position.x = x - 0.5;
                    m_vertex.position.y = y;
                    win_ref.draw(&m_vertex, 1, sf::Points);
                    x = x - m;
                }
            }else{
                std::cout << "CHECK 4" << '\n';
                for (y = m_points[0].getPointPos().y; y <= m_points[1].getPointPos().y; y++)
                {
                    m_vertex.position.x = x + 0.5;
                    m_vertex.position.y = y;
                    win_ref.draw(&m_vertex, 1, sf::Points);
                    x = x + m;
                }
            }
            }
        std::cout<<"m"<<m<<'\n';
        //std::cout<<"X1: "<<m_points[0].getPointPos().x<<m_points[0].getPointPos().x<<"Y1: "<<m_points[0].getPointPos().x<<m_points[0].getPointPos().x<<'\n';
        //std::cout<<"X2: "<<m_points[1].getPointPos().x<<m_points[1].getPointPos().x<<"Y2: "<<m_points[1].getPointPos().x<<m_points[1].getPointPos().x<<'\n';
    }

    int m_count_lines;
    sf::Vertex m_vertex;
    Point2D m_points[2];
    bool flipX;
    bool flipY;
    unsigned int m_choosen_algorithem;
};
