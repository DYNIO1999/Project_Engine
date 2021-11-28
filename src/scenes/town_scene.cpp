#include "town_scene.h"
#include "../core/entitylist.h"

Town_Scene::Town_Scene(Engine *engine_ref)
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
    sf::Clock testclock;

    //ImGui::SFML::Update((*m_Engine_ref->m_window), m_Engine_ref->m_engineClock.restart());
    m_Engine_ref->m_window->clear(sf::Color::White);
    ImGui::Begin("Welcome Town_Scene");
    if (ImGui::Button("Close Town scene"))
    {
        m_Engine_ref->m_scene_manager->popScene();
        ImGui::End();
        return;
    }
    ImGui::End();
    m_Engine_ref->m_window->draw(background_sprite);
    m_entitesPtr->draw((*m_Engine_ref->m_window));
    //ImGui::SFML::Render(*m_Engine_ref->m_window);
}
void Town_Scene::initData()
{
    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);
    std::shared_ptr<sf::Texture> test = ResourceManager::acquireTexture(ASSETS_PATH + "dirt.png");
    background_sprite.setTexture(*test);
    background_sprite.setPosition(0,0);
}
void Town_Scene::input()
{
    //std::cout<<"Input time"<<'\n';
}
