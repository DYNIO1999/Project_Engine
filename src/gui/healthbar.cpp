#include "healthbar.h"



HealthBar::HealthBar(float x, float y, float sizeX, float sizeY) 
{
    m_backHPbar.setPosition(x, y);
    m_backHPbar.setSize(sf::Vector2f(sizeX, sizeY));
    m_backHPbar.setFillColor(sf::Color(153, 0, 0, 255));
    m_backHPbar.setOutlineThickness(2.5);
    m_backHPbar.setOutlineColor(sf::Color(102, 0, 0, 255));

    m_frontHPBar.setPosition(x, y);
    m_frontHPBar.setSize(sf::Vector2f(sizeX, sizeY));
    m_frontHPBar.setFillColor(sf::Color::Red);
}

HealthBar::~HealthBar() 
{
    
}

void HealthBar::init(float x, float y, float sizeX, float sizeY) 
{
    m_backHPbar.setPosition(x, y);
    m_backHPbar.setSize(sf::Vector2f(sizeX, sizeY));
    m_backHPbar.setFillColor(sf::Color(153, 0, 0, 255));
    m_backHPbar.setOutlineThickness(2.5);
    m_backHPbar.setOutlineColor(sf::Color(102, 0, 0, 255));

    m_frontHPBar.setPosition(x, y);
    m_frontHPBar.setSize(sf::Vector2f(sizeX, sizeY));
    m_frontHPBar.setFillColor(sf::Color::Red);
}

void HealthBar::update(float sizeX, float x, float y) 
{
    m_frontHPBar.setSize(sf::Vector2f(sizeX, m_frontHPBar.getSize().y));
    m_frontHPBar.setPosition(x, y);
    m_backHPbar.setPosition(x, y);
}

void HealthBar::draw(sf::RenderWindow &window) 
{
    window.draw(m_backHPbar);
    window.draw(m_frontHPBar);
}

HealthBar::HealthBar() 
{
    
}
