#include "../core/core.h"
#include "battle_scene.h"

Battle_Scene::Battle_Scene(Engine *engine_ref) 
{
    m_Engine_ref = engine_ref;
    initData();
}

Battle_Scene::Battle_Scene(Engine *engine_ref, int battleMapType, int numberEnemies) 
{
    m_Engine_ref = engine_ref;
    initData();
    m_battleMapType = battleMapType;
    m_numberEnemies = numberEnemies;
}

int Battle_Scene::processEvents(TimeStep deltatime) 
{
    return 0;
}

void Battle_Scene::draw(TimeStep deltatime) 
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    ImGui::Begin("Welcome Battle_Scene");
    if (ImGui::Button("Close Battle scene"))
    {
        m_Engine_ref->m_scene_manager->popScene();
        ImGui::End();
        return;
    }
    ImGui::End();
    m_Engine_ref->m_window->draw(m_background);
}

void Battle_Scene::input() 
{
    
}

Battle_Scene::~Battle_Scene() 
{
    
}

void Battle_Scene::initData() 
{
    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);

    std::shared_ptr<sf::Texture> pbackgroundTexture = ResourceManager::acquireTexture(ASSETS_PATH + "example.png");
    m_background.setTexture(*pbackgroundTexture);
    m_background.setPosition(sf::Vector2f(0,0));
}
