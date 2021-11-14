#pragma once
#include "scene.h"
#include <iostream>


class World_Scene:public Scene{

private:
    
public:
    World_Scene(){}
    ~World_Scene(){}

    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;

private:
    void initData();
    void cleanupData();
};
