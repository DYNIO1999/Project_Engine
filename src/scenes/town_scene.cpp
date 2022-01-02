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
    attackbutton.ButtonUpdate();
    healthbutton.ButtonUpdate();

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
    m_Engine_ref->m_window->draw(m_inventorySprite);
    attackbutton.ButtonDraw(*m_Engine_ref->m_window);
    healthbutton.ButtonDraw(*m_Engine_ref->m_window);
    for (auto it = m_buttonnList.begin(); it < m_buttonnList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);

    }
    m_Engine_ref->m_window->draw(m_attackText);
    m_Engine_ref->m_window->draw(m_healthText);

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

    std::shared_ptr<sf::Texture> inventoryTexture = ResourceManager::acquireTexture(ASSETS_PATH + "inventory.png");
    m_inventorySprite.setTexture(*inventoryTexture);
    m_inventorySprite.setPosition(m_Engine_ref->m_window->getSize().x / 2 - 400.f, 200);

    std::shared_ptr<sf::Font> menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");
    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(70, 70, 70, 200);
    tempColors.hoverColor = sf::Color(20, 20, 20, 200);
    tempColors.idleColor = sf::Color(5, 46, 21, 200);
    attackbutton.initButton(735, 375, 72, 72, *menuFont, "+10", tempColors);
    healthbutton.initButton(735, 555, 72, 72, *menuFont, "+10", tempColors);

    //tbutton.initButton(735, 375, 72, 72, *menuFont, "+10", tempColors);

    attackbutton.setTextSize(20);
    attackbutton.setPosition(sf::Vector2f(0, -15));
    m_attackText.setFont(*ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf"));
    m_attackText.setFillColor(sf::Color::White);
    m_attackText.setCharacterSize(25);
    m_attackText.setScale(sf::Vector2f(1.2, 1.2));
    m_attackText.setOutlineColor(sf::Color::Black);
    m_attackText.setOutlineThickness(1.f);
    m_attackText.setLetterSpacing(2.f);
    m_attackText.setFillColor(sf::Color::Red);
    m_attackText.setString("Attack");
    m_attackText.setPosition(sf::Vector2f(490,400));

    healthbutton.setTextSize(20);
    healthbutton.setPosition(sf::Vector2f(0, -15));
    m_healthText.setFont(*ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf"));
    m_healthText.setFillColor(sf::Color::White);
    m_healthText.setCharacterSize(25);
    m_healthText.setScale(sf::Vector2f(1.2, 1.2));
    m_healthText.setOutlineColor(sf::Color::Black);
    m_healthText.setOutlineThickness(1.f);
    m_healthText.setLetterSpacing(2.f);
    m_healthText.setFillColor(sf::Color::Red);
    m_healthText.setString("Health");
    m_healthText.setPosition(sf::Vector2f(490, 580));
}

     /*
            std::shared_ptr<sf::Font> menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");

             Button_Colors tempColors;
             tempColors.pressedColor = sf::Color(70, 70, 70, 200);
             tempColors.hoverColor = sf::Color(20, 20, 20, 200);
             tempColors.idleColor = sf::Color(5, 46, 21, 200);

             int buttonwidth = 100;
             int buttonheight = 100;
             int buttonheight2 =100;
             int xpos = m_Engine_ref->m_window->getSize().x / 2 - buttonwidth / 2;
             int endxpos = m_Engine_ref->m_window->getSize().x;
             int endypos = m_Engine_ref->m_window->getSize().y;
             Button *energy = new Button();
             energy->initButton(xpos - (buttonwidth / 2), 300, buttonwidth, buttonheight, *menuFont, "+10", tempColors, sf::Vector2f(0, -24));

             Button *energy_exp = new Button();
             energy_exp->initButton(xpos + (buttonwidth / 2), 300, buttonwidth, buttonheight, *menuFont, "+10", tempColors, sf::Vector2f(0, -24));

             m_buttonnList.push_back(energy);
             m_buttonnList.push_back(energy_exp);
         }

      */

     void Town_Scene::input()
     {
         m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
         attackbutton.ButtonInput(m_mousePosition);
         m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
         healthbutton.ButtonInput(m_mousePosition);
         // std::cout<<"Input time"<<'\n';
}