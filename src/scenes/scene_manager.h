#pragma once
#include <vector>
#include "scene.h"
#include <iostream>


class SceneManager{
    
    public:
    SceneManager(Engine* m_Engine_ref); //default
    ~SceneManager();
    void changeScene(Scene* new_scene);
    void pushScene(Scene* new_scene);
    void popScene();
    std::vector<Scene*> m_Scene_Stack;
    Engine *m_Engine_ref;
    private:
};
