#pragma once
#include <SFML/Graphics.hpp>
#include "../core/timestep.h"
#include <memory>
#include <iostream>
/**  
* Klasa animacje sluzaca do tworzenia animacji
*/
class Animation
{
private:

public:
    /**  
    * Konstruktor klasy animacji
    */
    Animation(){
        
    }
    /**
     * Konstruktor klasy animacji
     * \param texture wskaznik na teksture.
     * \param imagecount vektor z iloscia obrazy w animacji.
     * \param switchtime czas zmiany animacji.
     */
    Animation(std::shared_ptr<sf::Texture> texture, sf::Vector2u imagecount, float switchtime)
    {
        m_imageCount =  imagecount;
        m_switchTime =  switchtime;
        m_totalTime =0.0f;
        m_currentImage.x=0;
        m_textureRect.width = texture->getSize().x / float(m_imageCount.x);
        m_textureRect.height = texture->getSize().y / float(m_imageCount.y);
    }
    /**
     * Destruktor klasy animacji
     */
    ~Animation(){
        
    }
    /**
     * Metoda inicjujaca klase animacji
     * \param texture wskaznik na teksture.
     * \param imagecount vektor z iloscia obrazy w animacji.
     * \param switchtime czas zmiany animacji.
     */
    void initAnimation(std::shared_ptr<sf::Texture> texture, sf::Vector2u imagecount, float switchtime){
        m_imageCount = imagecount;
        m_switchTime = switchtime;
        m_totalTime = 0.0f;
        m_currentImage.x = 0;
        m_textureRect.width = texture->getSize().x / float(m_imageCount.x);
        m_textureRect.height = texture->getSize().y / float(m_imageCount.y);
    }
    /**
     * Metoda aktualizujaca animacje
     * \param row aktualny sprite do wyswietlenia z tekstury.
     * \param dt deltatime.
     */
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

    /**
     * Wspolrzedne tekstury
     */
    sf::IntRect m_textureRect;
    /**
     * Ilosc obrazow w animacji
     */
    sf::Vector2u m_imageCount;
    /**
     * Aktualny obraz animacji
     */
    sf::Vector2u m_currentImage;
    /**
     * Calkowity czas animacji
     */
    float m_totalTime;
    /**
     * Czas zmiany animacji
     */
    float m_switchTime;
};


