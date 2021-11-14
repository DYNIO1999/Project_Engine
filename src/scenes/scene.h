#pragma once
#include "../core/timestep.h"
class Engine;

class Scene{
public:
    virtual ~Scene() {}
    virtual int processEvents(TimeStep deltatime)=0;
    virtual void draw(TimeStep deltatime) = 0;
    Engine* m_Engine_ref;
};