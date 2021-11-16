#pragma once 
#include <SFML/Graphics.hpp>
#include "command.h"

class InputHandler
{
private:

public:
    InputHandler(){
        buttonW = new MoveUpCommand();
        buttonS = new MoveDownCommand();
        buttonA = new MoveLeftCommand();
        buttonD = new MoveRightCommand();
        noInput = new NoInputCommand();
    }
    ~InputHandler(){
        delete buttonW;
        delete buttonS;
        delete buttonA;
        delete buttonD;
    }
    Command* handleInput(){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                return buttonW;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                return buttonS;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                return buttonA;
            } 
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                return buttonD;
            }
            return noInput;
    }
    Command *buttonW;
    Command *buttonA;
    Command *buttonS;
    Command *buttonD;
    Command *noInput;
};
