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
    testbutton.ButtonUpdate();
    m_entitesPtr->processEvents(deltatime);
    return 0;
}
void Town_Scene::draw(TimeStep deltatime)
{
    sf::Clock testclock;

    //ImGui::SFML::Update((*m_Engine_ref->m_window), m_Engine_ref->m_engineClock.restart());
    m_Engine_ref->m_window->clear(sf::Color::White);
    
    testbutton.ButtonDraw(*m_Engine_ref->m_window);

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

    std::shared_ptr<sf::Texture> backgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "city.png");
    background_sprite.setTexture(*backgroundTexture);
    background_sprite.setPosition(0,0);

    std::shared_ptr<sf::Font> testFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");
    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(70, 70, 70, 200);
    tempColors.hoverColor = sf::Color(20, 20, 20, 200);
    tempColors.idleColor = sf::Color(150, 150, 150, 200);
    testbutton.initButton(400, 400, 200, 75, *testFont, "BUTTON 1", tempColors);
}
void Town_Scene::input()
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    testbutton.ButtonInput(m_mousePosition);
    //std::cout<<"Input time"<<'\n';
}
