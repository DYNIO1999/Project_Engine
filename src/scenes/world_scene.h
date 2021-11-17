#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../input/inputhandler.h"
#include "../input/command.h"
#include "../tilemap/tilemap.h"
class World_Scene:public Scene{

private:
    
public:
    World_Scene(Engine *engine_ref);
    ~World_Scene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;

private:
    Tilemap* testmap;
    InputHandler* m_inputhandler;
    EntityList* m_entitesPtr;
    void initData();
    void cleanupData();
};
