#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../core/timestep.h"
#include "objectstates.h"
#include "../transforms/transforms.h"
#include "../collision/boxcollider.h"
#include <memory>

class Object{
    public:
    
    Object(){}
    virtual ~Object(){}

    virtual void processEvents(){

    }
    virtual int processEvents(TimeStep dt) =0;
    virtual void draw(sf::RenderWindow &win_ref) = 0;
    
    
    virtual void setSize(sf::Vector2f size)=0;
    virtual void setColor(sf::Color color)=0;
    virtual void setPosition(sf::Vector2f pos)=0;
    
    virtual void setScale(float scale){

    }
    virtual sf::Vector2f getPos()=0;
    virtual sf::Vector2f getSize()=0;
    virtual sf::Color getColor()=0;
    virtual void setPosition(sf::Vector2f start_pos, sf::Vector2f end_pos){

    }
    virtual sf::Vector2f getPosStartPoint(){
        return m_pos;
    }
    virtual sf::Vector2f getPosEndPoint(){
        return m_size;
    }
    virtual float getScale(){
        return m_scale;
    }

    virtual int getType(){
        return m_type;
    }
    virtual void setRadiusX(int radius){
    }
    virtual void setRadiusY(int radius){

    }
    virtual int getRadiusX(){
        return 0;
    }
    virtual int getRadiusY()
    {
        return 0;
    }
    virtual int getThickness(){
        return 0;
    }
    virtual void setThickness(int thickness){

    }

    virtual void scale(float scale){

    }
    virtual void translate(sf::Vector2f move){

    }
    virtual void rotate(float angle){

    }
    virtual void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {

    }
    virtual void setMoveState(int state){

    }
    virtual BoxCollider& getBoxCollider(){
        return m_colisionBox;
    }
    protected:
    BoxCollider m_colisionBox;
    Transforms m_transform; 
    int m_type;
    sf::Vector2f m_pos;
    sf::Vector2f m_size;
    sf::Color m_color;
    float m_scale;
    std::shared_ptr<sf::Texture> m_pTexture;
    sf::Sprite *m_curSprite;
    int m_movestate;
};