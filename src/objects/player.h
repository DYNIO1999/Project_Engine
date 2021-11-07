#pragma once
#include "object.h"
class Player :public Object
{
private:

public:
    Player(sf::Vector2f pos, sf::Vector2f size){
        m_player_shape.setFillColor(sf::Color::Red);
        m_pos =pos;
        m_size = size;
        m_player_shape.setPosition(m_pos);
        m_player_shape.setSize(m_size);
    }
    ~Player(){
        
    }
    void processEvents(TimeStep dt){
        //std::cout<<"Updating Player"<<std::endl;
        m_player_shape.setPosition(m_pos);
        m_player_shape.setSize(m_size);
        //std::cout << "Y"<< m_pos.y << std::endl;
    }
    void draw(sf::RenderWindow &win_ref){
        win_ref.draw(m_player_shape);
    }
    void setSize(sf::Vector2f size)
    {
        m_size=size;
    }
    void setColor(sf::Color color){
        m_color=color;
    }
    void setPosition(sf::Vector2f pos){
        m_pos=pos;
    }
    void setScale(float scale){
        m_scale=scale;
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
    float getScale(){
        return m_scale;
    }
    void setTexture(sf::Texture* texture){
        m_curTexture = texture;
    }

    public:
    sf::RectangleShape m_player_shape;
};

