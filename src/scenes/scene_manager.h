#pragma once
#include <vector>
#include "scene.h"
#include <iostream>
#include "../core/timestep.h"

/**  
* Klasa SceneManager sluzy do obslugi scen naszej gry
*/
class SceneManager{
    
    public:
    SceneManager(Engine* m_Engine_ref); 
    ~SceneManager();
    void changeScene(Scene* new_scene);
    void pushScene(Scene* new_scene);
    void popScene();
    void drawScene();
    void processScene();
    void inputScene();
    std::vector<Scene*> m_Scene_Stack;
    Engine *m_Engine_ref;
    private:
};
