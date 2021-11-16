#pragma once
#include <SFML/Graphics.hpp>
#include "../core/timestep.h"
#include <memory>
class Animation
{
private:

public:
    Animation(std::shared_ptr<sf::Texture> texture, sf::Vector2u imagecount, float switchtime)
    {
        m_imageCount =  imagecount;
        m_switchTime =  switchtime;
        m_totalTime =0.0f;
        m_currentImage.x=0;
        m_textureRect.width = texture->getSize().x / float(m_imageCount.x);
        m_textureRect.height = texture->getSize().y / float(m_imageCount.y);
    }
    ~Animation(){
        
    }
    void Update(int row, TimeStep dt){
        m_currentImage.y=row;
        m_totalTime = m_totalTime+dt.m_time;
        if(m_totalTime>=m_switchTime){
            m_totalTime = m_totalTime - m_switchTime;
            m_currentImage.x = m_currentImage.x +1;
            if (m_currentImage.x >=m_imageCount.x)
            {
                m_currentImage.x = 0;
            }
        }
        m_textureRect.left = m_currentImage.x * m_textureRect.width;
        m_textureRect.top = m_currentImage.y * m_textureRect.height;
    }
    sf::IntRect m_textureRect;
    sf::Vector2u m_imageCount;
    sf::Vector2u m_currentImage;
    float m_totalTime;
    float m_switchTime;
};


