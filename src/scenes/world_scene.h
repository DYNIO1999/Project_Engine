#pragma once
#include "scene.h"
#include <iostream>

//namespace DEngine{
class World_Scene:public Scene{

private:
    
public:
    World_Scene(){}
    ~World_Scene(){}
    void processEvents() override;
    void draw() override;
};
//};

//Zaimplementuj klase  World_Scene
//Pamietaj aby zdziedziczyc z interfejsu oraz wpisz ja do DEngine namespace <3