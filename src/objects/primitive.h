#pragma once
#include <iostream>
#include <vector>
#include "object.h"
#include "../renderer/linesegment.h"
#include "../renderer/circlesegment.h"

//DYNIEK TEN KOD TRZEBA POTEM PRZENIESC DO .CPP TY IDIOTO!

class Primitive: public  Object
{
public:
    Primitive(int type, sf::Vector2f pos, sf::Vector2f size, sf::Color color){
        m_type =type;
        m_pos =pos;
        m_size =size;
        m_color =color;
        if(m_type==PRIMITIVE_POINT){
            m_vertices = new sf::Vertex[1];
            m_vertices[0].position.x = m_pos.x;
            m_vertices[0].position.y = m_pos.y;
            m_vertices[0].color = m_color;
        }
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
    }
    Primitive(int type, sf::Vector2f start_pos, sf::Vector2f end_pos, sf::Color color, int algo_line_index)
    {
        m_type = type;
        m_pos =start_pos;
        m_color = color;
        m_size = end_pos; 
        m_algo_type = algo_line_index;
        if (m_type == PRIMITIVE_LINE)
        {
            m_line = new LineSegment(sf::Vector2i(m_pos.x, m_pos.y), sf::Vector2i(m_size.x, m_size.y),0,m_algo_type);
        }
    }
    Primitive(int type,std::vector<sf::Vector2f>& arr,sf::Color color, int algo_line_index)
    {
        m_type = type;
        m_color = color;
        m_algo_type = algo_line_index;
        if(m_type==PRIMITIVE_LINES){
            m_lines_size =(int)(arr.size()/2);
            m_line = new LineSegment[m_lines_size];
            int j=0;
            for(int i=0;i<m_lines_size;i++){
                m_line[i].setAlgorithmType(algo_line_index);
                m_line[i].setPos(sf::Vector2i(arr[j]), sf::Vector2i(arr[j+1]));
                m_line[i].setThickness(1);
                j=j+2;
            }
        }
        else if (m_type == PRIMITIVE_POLYGON)
        {
            m_lines_size = (int)(arr.size() / 2);
            m_line = new LineSegment[m_lines_size];
            int j = 0;
            for (int i = 0; i < m_lines_size; i++)
            {
                m_line[i].setAlgorithmType(algo_line_index);
                m_line[i].setPos(sf::Vector2i(arr[j]), sf::Vector2i(arr[j + 1]));
                m_line[i].setThickness(1);
                j = j + 2;
            }
            for(int i=0;i<m_lines_size;i++){
                for (int j = i; j <=(m_lines_size-1); j++)
                {
                    if(m_cancreatePolygon){
                    m_cancreatePolygon=check_create_polygon(sf::Vector2f(m_line[i].getStartPos()), sf::Vector2f(m_line[i].getEndPos()), sf::Vector2f(m_line[j].getStartPos()), sf::Vector2f(m_line[j].getEndPos()));
                    }
                    std::cout<<i<<j<<" : "<<m_cancreatePolygon<<'\n';
                }
            }
            if(!m_cancreatePolygon){
                std::cout<<"Cant create polygon!"<<'\n';
            }
        }
    }
    Primitive(int type,sf::Vector2f pos,int radius,sf::Color color, int algo_index)
    {
        m_type = type;
        m_algo_type = algo_index;
        m_pos = pos;
        m_radiusX = radius;
        m_color =color;
        if (m_type == PRIMITIVE_CIRCLE){
            m_circle =  new CircleSegment(sf::Vector2i(m_pos),m_radiusX,m_algo_type);
        }
    }
    Primitive(int type, sf::Vector2f pos, int radiusX, int radiusY, sf::Color color, int algo_index)
    {
        m_type = type;
        m_algo_type = algo_index;
        m_pos = pos;
        m_radiusX = radiusX;
        m_radiusY = radiusY;
        m_color = color;
        if (m_type == PRIMITIVE_ELLIPSE)
        {
            m_circle = new CircleSegment(sf::Vector2i(m_pos), m_radiusX,m_radiusY,m_algo_type);
        }
    }
    ~Primitive()
        {
            std::cout << "PRIMITIVE TYPE: " << m_type << '\n';
            if(m_type == PRIMITIVE_LINE)
            {
                delete m_line;
            }else if(m_type==PRIMITIVE_LINES){
                delete[] m_line;
            }
            else if (m_type == PRIMITIVE_CIRCLE)
            {
                delete m_circle;
            }else if(m_type == PRIMITIVE_ELLIPSE){
                delete m_circle;
            }else if(m_type == PRIMITIVE_POLYGON){
                delete[] m_line;
            }
            else
            {
                delete[] m_vertices;
            }
        }
        void draw(sf::RenderWindow & win_ref)
        {
            if (m_type == PRIMITIVE_POINT)
            {
                win_ref.draw(m_vertices, 1, sf::Points);
            }
            if (m_type == PRIMITIVE_TRIANGLE)
            {
                win_ref.draw(m_vertices, 3, sf::Triangles);
            }
            if (m_type == PRIMITIVE_QUAD)
            {
                win_ref.draw(m_vertices, 4, sf::Quads);
            }
            if (m_type == PRIMITIVE_LINE)
            {
                m_line->draw(win_ref, m_color);
            }
            if (m_type == PRIMITIVE_LINES){
                for(int i=0;i<m_lines_size;i++){
                    m_line[i].draw(win_ref, m_color);
                }
            }
            if (m_type == PRIMITIVE_POLYGON){
                if(m_cancreatePolygon){
                for(int i=0;i<m_lines_size;i++){
                    m_line[i].draw(win_ref, m_color);
                }   
                }
            }
            if(m_type==PRIMITIVE_CIRCLE){
                m_circle->draw(win_ref, m_color);
            }
            if (m_type == PRIMITIVE_ELLIPSE)
            {
                m_circle->draw(win_ref, m_color);
            }
        }
        void setSize(sf::Vector2f size)
        {
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
        }
        void setColor(sf::Color color)
        {
            m_color = color;
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
        }
        void setPosition(sf::Vector2f pos)
        {
            m_pos = pos;
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
            if (m_type == PRIMITIVE_CIRCLE){
                m_circle->setPos(sf::Vector2i(m_pos));
            }
        }
        void setPosition(sf::Vector2f start_pos, sf::Vector2f end_pos)
        {
            if(m_type==PRIMITIVE_LINE){
                m_pos = start_pos;
                m_size = end_pos;
                m_line->setPos(sf::Vector2i(m_pos.x, m_pos.y), sf::Vector2i(m_size.x, m_size.y));
            }
        }
        void setRadiusX(int radius)
        {
            m_radiusX = radius;
            m_circle->setRadX(m_radiusX);
        }
        int getRadiusX(){
            return  m_circle->getRadX();
        }
        void setRadiusY(int radius)
        {
            m_radiusY = radius;
            m_circle->setRadY(m_radiusY);
        }
        int getRadiusY()
        {
            return m_circle->getRadY();
        }

        sf::Vector2f getPosStartPoint()
        {
            return m_pos;
        }
        sf::Vector2f getPosEndPoint()
        {
            return m_size;
        }

        int getType()
        {
            return m_type;
        }
        sf::Vector2f getPos()
        {
            return m_pos;
        }
        sf::Vector2f getSize()
        {
            return m_size;
        }
        sf::Color getColor()
        {
            return m_color;
        }
        int getThickness(){
            if(m_line || m_circle){
                if(m_type == PRIMITIVE_LINE){
                    return m_line->getThickness();
                }
                else if (m_type == PRIMITIVE_LINES)
                {
                    return m_line[0].getThickness();
                }else if(m_type == PRIMITIVE_CIRCLE){
                    return m_circle->getThickness();
                }
                else if (m_type ==PRIMITIVE_ELLIPSE){
                    return m_circle->getThickness();
                }
            }
            return -1;
        }
        void setThickness(int thickness){
            if(thickness>0){
                if ((m_type == PRIMITIVE_ELLIPSE)||(m_type == PRIMITIVE_CIRCLE)){
                m_circle->setThickness(thickness);
                }
                else if (m_type == PRIMITIVE_LINE){
                m_line->setThickness(thickness);
                }
            }
        }
    private:
        bool check_create_polygon(sf::Vector2f a_start, sf::Vector2f a_end, sf::Vector2f b_start, sf::Vector2f b_end)
        {
            float s1,s2,s3, s4;
            float matrixA[3][3];
            float matrixB[3][3];
            float matrixC[3][3];
            float matrixD[3][3];

            matrixA[2][0]=1.0;
            matrixA[2][1]=1.0;
            matrixA[2][2]=1.0;
            matrixA[0][0]=a_start.x;
            matrixA[1][0]=a_start.y;
            matrixA[0][1]=b_start.x;
            matrixA[1][1]=b_start.y;
            matrixA[0][2]=b_end.x;
            matrixA[1][2]=b_end.y;
            s1=calculateDet(matrixA);

            
            matrixB[2][0] = 1.0;
            matrixB[2][1] = 1.0;
            matrixB[2][2] = 1.0;
            matrixB[0][0] =a_end.x;
            matrixB[1][0] =a_end.y;
            matrixB[0][1] = b_start.x;
            matrixB[1][1] = b_start.y;
            matrixB[0][2] = b_end.x;
            matrixB[1][2] = b_end.y;
            s2 = calculateDet(matrixB);

            matrixC[2][0] = 1.0;
            matrixC[2][1] = 1.0;
            matrixC[2][2] = 1.0;
            matrixC[0][0] =b_start.x;
            matrixC[1][0] = b_start.y;
            matrixC[0][1] = a_start.x;
            matrixC[1][1] = a_start.y;
            matrixC[0][2] = a_end.x;
            matrixC[1][2] = a_end.y;
            s3 = calculateDet(matrixC);


            matrixD[2][0] = 1.0;
            matrixD[2][1] = 1.0;
            matrixD[2][2] = 1.0;
            matrixD[0][0] = b_end.x;
            matrixD[1][0] = b_end.y;
            matrixD[0][1] = a_start.x;
            matrixD[1][1] = a_start.y;
            matrixD[0][2] = a_end.x;
            matrixD[1][2] = a_end.y;

            s4= calculateDet(matrixD);

            if (((s1<0)&&(s2> 0)&&(s3 > 0)&&(s4 < 0)) || ((s1 > 0)&&(s2 < 0)&&(s3 < 0)&&(s4 > 0))){
                return false;
            }
            return true;
        }
        template <int rows, int cols>
        float calculateDet(float (&arr)[rows][cols])
        {
            float result = (arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[2][1] * arr[1][2]))) -
                           (arr[0][1] * (((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0])))) + (arr[0][2] * (((arr[1][0] * arr[2][1]) - (arr[2][0] * arr[1][1]))));
            return result;
        }

    private:
    int m_lines_size;
    CircleSegment* m_circle;
    sf::Vertex *m_vertices;
    LineSegment* m_line;
    unsigned int m_algo_type;
    int m_radiusX;
    int m_radiusY;
    bool m_cancreatePolygon = true;
    };
