#pragma once
#include "../core/core.h"
class HealthBar
{
public:
    HealthBar();
    HealthBar(float x, float y, float sizeX, float sizeY);
    ~HealthBar();
    void init(float x, float y, float sizeX, float sizeY);

    void update(float sizeX, float x, float y);
    void draw(sf::RenderWindow &window);
    void setBackBarSize(float size);
private:
    sf::RectangleShape m_backHPbar;
    sf::RectangleShape m_frontHPBar;
};
