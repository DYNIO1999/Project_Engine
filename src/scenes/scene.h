#pragma once
#include "../core/timestep.h"
/**  
* Pre-definicja klasy Engine
*/
class Engine;
/**  
* Klasa wirtualna czyli nadrzedna do scen
*/
class Scene{
public:
    /**
     * @brief Destruktor
     * 
     */
    virtual ~Scene() {}
    /**
     * @brief Metoda aktualizujaca
     * 
     * @param deltatime deltatime
     * @return int 
     */
    virtual int processEvents(TimeStep deltatime)=0;
    /**
     * @brief Metoda rysujac
     * 
     * @param deltatime deltatime
     */
    virtual void draw(TimeStep deltatime) = 0;
    /**
     * @brief Metoda pobierajaca input
     * 
     */
    virtual void input(){
        
    }
    /**
     * Wskaznik na silnik gry
     *
     */
    Engine* m_Engine_ref;
};