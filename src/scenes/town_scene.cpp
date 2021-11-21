#include "town_scene.h"
#include "../core/entitylist.h"

Town_Scene::Town_Scene(Engine*  engine_ref)
{
    m_Engine_ref=engine_ref;
    m_entitesPtr = new EntityList();
    initData();
}
Town_Scene::~Town_Scene()
{
    delete m_entitesPtr;
}
int Town_Scene::processEvents(TimeStep deltatime)
{
    m_entitesPtr->processEvents(deltatime);
    return 0;
}
void Town_Scene::draw(TimeStep deltatime)
{
    /*ImGui::SFML::Update((*m_Engine_ref->m_window), m_Engine_ref->m_engineClock.restart());
    ImGui::Begin("Welcome Town_Scene");
    if (ImGui::Button("Close Town scene"))
    {
        m_Engine_ref->m_scene_manager->popScene();
    }
    ImGui::End();
    m_Engine_ref->m_window->draw(background_sprite);
    ImGui::SFML::Render(*m_Engine_ref->m_window);*/
    m_entitesPtr->draw((*m_Engine_ref->m_window));
    //m_Engine_ref->m_window->draw(background_sprite);
}
void Town_Scene::initData()
{
    std::shared_ptr<sf::Texture> test = ResourceManager::acquireTexture(ASSETS_PATH + "dirt.png");
    background_sprite.setTexture(*test);
    background_sprite.setPosition(0,0);
    ResourceManager::cleanUpOrphans();
}
void Town_Scene::input()
{
    
}
