#pragma once 
#include <SFML/Graphics.hpp>
#include "command.h"
/**  
* Klasa zawiera obsluge inputu
*/
class InputHandler
{
private:

public:
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */

    /**
     * Konstruktor klasy InputHandler
     */
    InputHandler(){
        buttonW = new MoveUpCommand();
        buttonS = new MoveDownCommand();
        buttonA = new MoveLeftCommand();
        buttonD = new MoveRightCommand();
        noInput = new NoInputCommand();
    }
    /**
     * Destruktor klasy InputHandler
     */
    ~InputHandler(){
        delete buttonW;
        delete buttonS;
        delete buttonA;
        delete buttonD;
    }
    /**
     * Metoda realizujaca poruszanie zwraca obiekt Command
     */
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
    /**
     * Wskanizk na obiekt Command
     */
    Command *buttonW;
    /**
     * Wskanizk na obiekt Command
     */
    Command *buttonA;
    /**
     * Wskanizk na obiekt Command
     */
    Command *buttonS;
    /**
     * Wskanizk na obiekt Command
     */
    Command *buttonD;
    /**
     * Wskanizk na obiekt Command
     */
    Command *noInput;
};
