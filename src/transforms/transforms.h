#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
/**  
* Klasa Transforms sluzy do przeprowadzania prostych operacji na obiektach
*/
class Transforms
{
private:
public:
    Transforms()
    {

    }
    ~Transforms()
    {

    }
    sf::Vector2f translate(sf::Vector2f orgin, sf::Vector2f move){
        sf::Vector2f newpos;
        newpos.x = orgin.x + move.x;
        newpos.y = orgin.y + move.y;
        return newpos;
    }
    sf::Vector2f rotate(sf::Vector2f curpos, sf::Vector2f point0, float angle)
    {
        sf::Vector2f newpos;
        newpos.x = point0.x + (curpos.x - point0.x) * cos(angle * M_PI / 180) - (curpos.y - point0.y) * sin(angle * M_PI / 180);
        newpos.y = point0.y + (curpos.x - point0.x) * sin(angle * M_PI / 180) - (curpos.y - point0.y) * cos(angle * M_PI / 180);
        return newpos; 
    }
    sf::Vector2f scale(sf::Vector2f curpos, sf::Vector2f point0, float scale){
        sf::Vector2f newscale;
        newscale.x = curpos.x* scale + (1-scale) * point0.x;
        newscale.y = curpos.y* scale + (1-scale) * point0.y;
        return newscale;
    } 
    sf::Vector2f scale(sf::Vector2f curpos, float scale)
    {
        sf::Vector2f newscale;
        newscale.x = curpos.x* scale;
        newscale.y = curpos.y* scale;
        return newscale;
    }
};

