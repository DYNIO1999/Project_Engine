#pragma once
#include "object.h"

class Static_Object:public Object{
    public:
    ~Static_Object(){}
    
    void processEvents() override;
    void draw(sf::RenderWindow &win_ref) override;
    void setPosition(float x, float y) override{

    };
    void setSize(float width, float height) override{

    };
    void setColor(sf::Color color){
        
    }

    float m_scale;

    float m_width;
    float m_height;
    float x;
    float y;

    private:
};