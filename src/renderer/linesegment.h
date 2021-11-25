#pragma once
#include "point2d.h"
#include "primitivetypes.h"

/**  
* Klasa Line sluzy do tworzenia lini o podanym typie algorytmu ktory uzylismy
*/
class LineSegment
{
public:
    LineSegment(sf::Vector2i start_point, sf::Vector2i end_point, int count_lines, int algorithm_index = LINE_DEFAULT_ALGORITHM)
    {
        m_points[0].setPointPos(start_point);
        m_points[1].setPointPos(end_point);
        m_choosen_algorithem = algorithm_index;
        m_thickness = 1;
    }
    LineSegment() = default;
    ~LineSegment()
    {
    }
    void draw(sf::RenderWindow &win_ref, sf::Color color)
    {
        if (m_choosen_algorithem == LINE_DEFAULT_ALGORITHM)
        {
            m_vertex[0].color = color;
            m_vertex[1].color = color;
            drawLineDefault(win_ref);
            
        }
        else if (m_choosen_algorithem == LINE_NAIVE_ALGORITHM)
        {
            m_vertex[0].color = color;
            drawLineNaive(win_ref);
        }
    }
    void setPos(sf::Vector2i start_point, sf::Vector2i end_point)
    {
        if(m_choosen_algorithem==LINE_NAIVE_ALGORITHM){
        if((start_point.x>=end_point.x)&&(start_point.y>=end_point.y)){
            m_points[0].setPointPos(end_point);
            m_points[1].setPointPos(start_point);
        }else{
        m_points[0].setPointPos(start_point);
        m_points[1].setPointPos(end_point);
        }
        }
        if (m_choosen_algorithem ==LINE_DEFAULT_ALGORITHM){
            m_points[0].setPointPos(start_point);
            m_points[1].setPointPos(end_point);
        }
    }
    sf::Vector2i getStartPos(){
        return m_points[0].getPointPos();
    }
    sf::Vector2i getEndPos(){
        return m_points[1].getPointPos();
    }
    void setAlgorithmType(int algorithm_type =LINE_DEFAULT_ALGORITHM)
    {
        m_choosen_algorithem = algorithm_type;
    }
    int getAlgorithmType(){
        return m_choosen_algorithem;
    }
    int getThickness(){
        return m_thickness;
    }
    void setThickness(int thickness){
        if(thickness>0){
            m_thickness= thickness;
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
                    for (x = m_points[0].getPointPos().x; x >= m_points[1].getPointPos().x; x--)
                    {
                        for(int k=0;k<m_thickness;k++){
                        m_vertex[0].position.x = x;
                        m_vertex[0].position.y = y + 0.5 - k;
                        win_ref.draw(&m_vertex[0], 1, sf::Points);
                        }
                        y = y + m;
                    }
                }
                else if ((m_points[1].getPointPos().x >= m_points[0].getPointPos().x) && (m_points[1].getPointPos().y <= m_points[0].getPointPos().y))
                {
                    for (x = m_points[0].getPointPos().x; x <= m_points[1].getPointPos().x; x++)
                    {
                        for(int k=0;k<m_thickness;k++){
                        m_vertex[0].position.x = x;
                        m_vertex[0].position.y = y - 0.5+k;
                        win_ref.draw(&m_vertex[0], 1, sf::Points);
                        }
                        y = y - m;
                    }
                }
                else
                {
                    for (x = m_points[0].getPointPos().x; x <= m_points[1].getPointPos().x; x++)
                    {
                        for(int k=0;k<m_thickness;k++){
                        m_vertex[0].position.x = x;
                        m_vertex[0].position.y = y + 0.5+k;
                        win_ref.draw(&m_vertex[0], 1, sf::Points);
                        }
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
                for (y = m_points[0].getPointPos().y; y <= m_points[1].getPointPos().y; y++)
                {
                    for(int k=0;k<m_thickness;k++){
                    m_vertex[0].position.x = x - 0.5 +k;
                    m_vertex[0].position.y = y;
                    win_ref.draw(&m_vertex[0], 1, sf::Points);
                    }
                    x = x - m;
                }
            }
            else if ((m_points[1].getPointPos().x >= m_points[0].getPointPos().x) && (m_points[1].getPointPos().y <= m_points[0].getPointPos().y)){
                for (y = m_points[0].getPointPos().y; y >= m_points[1].getPointPos().y; y--)
                {
                    for(int k=0;k<m_thickness;k++){
                    m_vertex[0].position.x = x + 0.5+k;
                    m_vertex[0].position.y = y;
                    win_ref.draw(&m_vertex[0], 1, sf::Points);
                    }
                    x = x + m;
                }
            }else{
                for (y = m_points[0].getPointPos().y; y <= m_points[1].getPointPos().y; y++)
                {
                    for(int k=0;k<m_thickness;k++){
                    m_vertex[0].position.x = x + 0.5+k;
                    m_vertex[0].position.y = y;
                    win_ref.draw(&m_vertex[0], 1, sf::Points);
                    }
                    x = x + m;
                }
            }
            }
    }
    void drawLineDefault(sf::RenderWindow &win_ref)
    {
        m_vertex[0].position = sf::Vector2f(m_points[0].getPointPos());
        m_vertex[1].position = sf::Vector2f(m_points[1].getPointPos());

        win_ref.draw(m_vertex, 2, sf::Lines);
    }

    sf::Vertex m_vertex[2];
    Point2D m_points[2];
    unsigned int m_choosen_algorithem;
    public:
    int m_thickness;
};
