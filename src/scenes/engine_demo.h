#pragma once
#include "scene.h"
#include "../core/core.h"
#include "../renderer/bitmaphandler.h"
class Engine_Demo : public Scene
{

private:
public:
    Engine_Demo(Engine *engine_ref)
    {
        this->m_Engine_ref = engine_ref; 
        initData();
    }
    ~Engine_Demo();

    int processEvents(TimeStep deltatime);
    void draw(TimeStep deltatime);

private:
    void initData();
    void cleanupData(){

    }

    
    
    BitmapHandler BitmapHandler1;
    BitmapHandler BitmapHandler2;
    int counter;
    float color[3] = {0.0f, 0.0f, 0.0f};
    float color2[3] = {0.0f, 0.0f, 0.0f};
    float pos[2] = {0.0f, 0.0f};
    float size[2] = {0.0f, 0.0f};
    float pos1[2] = {0.0f, 0.0f};
    float size1[2] = {0.0f, 0.0f};

    float vec4f[4];
};
