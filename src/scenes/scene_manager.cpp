#include "scene_manager.h"
#include "../core/core.h"
//using namespace DEngine;

SceneManager::SceneManager(Engine * m_Engine_ref)
{
    this->m_Engine_ref = m_Engine_ref;
}
SceneManager::~SceneManager()
{
    std::cout << "Clearing Data!" << '\n';
    std::cout<<"SIZE SCENE STACK"<<m_Scene_Stack.size()<<std::endl;
    for(auto it = m_Scene_Stack.begin(); it!=m_Scene_Stack.end();it++){
        delete (*it);
    }
    m_Scene_Stack.clear();
    std::cout<<"SIZE SCENE STACK"<<m_Scene_Stack.size()<<std::endl;
}
void SceneManager::changeScene(Scene *new_scene)
{
    delete m_Scene_Stack.back();
    m_Scene_Stack.pop_back();
    m_Scene_Stack.push_back(new_scene);
}
void SceneManager::pushScene(Scene *new_scene)
{
    m_Scene_Stack.push_back(new_scene);
}
void SceneManager::popScene(){
    delete m_Scene_Stack.back();
    m_Scene_Stack.pop_back();
}
void SceneManager::processScene()
{
    m_Scene_Stack.back()->processEvents(m_Engine_ref->getDeltaTime());
}
void SceneManager::drawScene()
{
    m_Scene_Stack.back()->draw(m_Engine_ref->getDeltaTime());
}