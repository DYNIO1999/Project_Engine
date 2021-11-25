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
    virtual ~Scene() {}
    virtual int processEvents(TimeStep deltatime)=0;
    virtual void draw(TimeStep deltatime) = 0;
    virtual void input(){
        
    }
    Engine* m_Engine_ref;
};