#pragma once
#include "scene.h"
#include "../core/core.h"
#include "../renderer/bitmaphandler.h"
#include "../core/entitylist.h"
#include "../input/inputhandler.h"
#include "../input/command.h"

/**  
* Klasa Engine_Demo implementuje nam nasza scene silnika jako scena demo czyli scena testowa
*/
class Engine_Demo : public Scene
{

private:
public:
    Engine_Demo(Engine *engine_ref)
    {
        this->m_Engine_ref = engine_ref;
        gameObjectsListPtr = new EntityList();
        m_inputhandler = new InputHandler();
        initData();
    }
    ~Engine_Demo();

    int processEvents(TimeStep deltatime);
    void draw(TimeStep deltatime);

private:
    void initData();
    void cleanupData(){

    }

    EntityList* gameObjectsListPtr;

    InputHandler *m_inputhandler;
    BitmapHandler BitmapHandler1;
    BitmapHandler BitmapHandler2;
    void input();
    int counter;
    float color[3] = {0.0f, 0.0f, 0.0f};
    float color2[3] = {0.0f, 0.0f, 0.0f};
    float pos[2] = {0.0f, 0.0f};
    float size[2] = {0.0f, 0.0f};
    float pos1[2] = {0.0f, 0.0f};
    float size1[2] = {0.0f, 0.0f};
    float thickness =1;
    float vec4f[4];
};
