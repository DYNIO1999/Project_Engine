#pragma once
#include "scene.h"
#include <iostream>
#include <memory>
#include "../core/entitylist.h"
#include "../input/inputhandler.h"
#include "../input/command.h"
#include "../tilemap/tilemap.h"
#include "../tilemap/tilemapeditor.h"
class World_Scene:public Scene{

public:
    World_Scene(Engine *engine_ref);
    ~World_Scene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;

private:
    Tilemap* testmap;
    InputHandler* m_inputhandler;
    EntityList* m_entitesPtr;
    TileMapEditor* m_mapeditor;
    
    void initData();
    void input();
    void cleanupData();
};
