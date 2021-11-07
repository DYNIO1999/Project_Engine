#pragma once 
#include <SFML/Graphics.hpp>
#include "command.h"

class InputHandler
{
private:

public:
    InputHandler(sf::RenderWindow* win_ptr){
        this->win_ptr = win_ptr;
        buttonW = new MoveUpCommand();
        buttonS = new MoveDownCommand();
        buttonA = new MoveLeftCommand();
        buttonD = new MoveRightCommand();
    }
    ~InputHandler(){
        delete buttonW;
        delete buttonS;
        delete buttonA;
        delete buttonD;
    }
    void handleInput(Object* obj){
        //while (win_ptr->pollEvent(event))
        //{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                buttonW->execute(obj);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                buttonS->execute(obj);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                buttonA->execute(obj);
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                buttonD->execute(obj);
            }
        //}
    }
    Command *buttonW;
    Command *buttonA;
    Command *buttonS;
    Command *buttonD;
    sf::Event event;
    sf::RenderWindow* win_ptr;
};
