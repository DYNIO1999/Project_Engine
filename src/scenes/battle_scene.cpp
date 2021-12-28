#include "../core/core.h"
#include "battle_scene.h"
#include "../objects/player.h"

Battle_Scene::Battle_Scene(Engine *engine_ref) 
{
    m_Engine_ref = engine_ref;
    initData();
}

Battle_Scene::Battle_Scene(Engine *engine_ref, int battleMapType, int numberEnemies) 
{
    m_Engine_ref = engine_ref;
    m_battleMapType = battleMapType;
    m_numberEnemies = numberEnemies;
    initData();
}

int Battle_Scene::processEvents(TimeStep deltatime) 
{

    for (int i = 0; i < ((int)m_buttonList.size()); i++)
    {
        m_buttonList[i]->ButtonUpdate();
    }
    m_entitesPtr->processEvents(deltatime);

   
   
   
    if (m_entitesPtr->getObject("PLAYER_BATTLE")->getBoxCollider().contains(m_mousePosition))
        {
            if (m_Engine_ref->event.mouseButton.button == sf::Mouse::Left)
            {
                if (m_Engine_ref->event.type == sf::Event::MouseButtonPressed)
                {
                    std::cout << "ONCE" << '\n';
                }
            }
        }

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
    m_Engine_ref->m_window->draw(m_GUIbar);
    
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);
    }
    m_entitesPtr->draw((*m_Engine_ref->m_window));
}

void Battle_Scene::input() 
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonInput(m_mousePosition, *m_Engine_ref);
    }

   /* for (auto it = m_entitesPtr->m_entities.begin(); it != m_entitesPtr->m_entities.end(); it++)
    {
        if(it->first!="PLAYER_BATTLE"){
        it->second->getBoxCollider().contains(m_mousePosition);
        if (m_Engine_ref->event.mouseButton.button == sf::Mouse::Left)
        {
            if (m_Engine_ref->event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "ONCE" << '\n';
            }
        }
        }
    }*/
}

Battle_Scene::~Battle_Scene() 
{
    cleanupData();
    m_entitesPtr->cleanUp();
    delete m_entitesPtr;

}

void Battle_Scene::initData() 
{
    m_entitesPtr = new EntityList();

    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);

    std::shared_ptr<sf::Texture> pbackgroundTexture;

    std::shared_ptr<sf::Font> menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");

    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(0, 0, 0, 255);
    tempColors.hoverColor = sf::Color(20, 20, 20, 255);
    tempColors.idleColor = sf::Color(5, 46, 21, 255);

    int buttonwidth = 500;
    int buttonheight = 100;

    Button *endturnButton = new Button();
    endturnButton->initButton(m_Engine_ref->m_window->getSize().x/2-buttonwidth/2, m_Engine_ref->m_window->getSize().y - (buttonheight+2.5), buttonwidth, buttonheight, *menuFont, "END TURN", tempColors, sf::Vector2f(0, -24));

    m_buttonList.push_back(endturnButton);

    if(m_battleMapType ==DESERT_MAP_TYPE){
        pbackgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "battle1.png");
        m_background.setTexture(*pbackgroundTexture);
        m_background.setPosition(sf::Vector2f(0, 0));
        m_background.setScale(sf::Vector2f(2.5, 1.5));
    }
    else if (m_battleMapType == MOUNTAIN_MAP_TYPE)
    {
        pbackgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "battle2.png");
        m_background.setTexture(*pbackgroundTexture);
        m_background.setPosition(sf::Vector2f(0, 0));
        m_background.setScale(sf::Vector2f(6,6));
    }

    m_GUIbar.setPosition(sf::Vector2f(0, m_Engine_ref->m_window->getSize().y-105));
    m_GUIbar.setSize(sf::Vector2f(1600, 105));
    m_GUIbar.setFillColor(sf::Color(5, 46, 21, 200));
    m_GUIbar.setOutlineColor(sf::Color::Black);
    m_GUIbar.setOutlineThickness(1.f);

    

    std::shared_ptr<sf::Texture> pPlayerAttackTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_AttackNoMovement.png");
    std::shared_ptr<sf::Texture> pPlayerDeathTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_DeathNoMovement.png");
    std::shared_ptr<sf::Texture> pPlayerHitTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_Hit.png");
    std::shared_ptr<sf::Texture> pPlayerIdleTexture =  ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_Idle.png");

    m_entitesPtr->addEntity("PLAYER_BATTLE", new Player(pPlayerDeathTexture, sf::Vector2f(400, 400), sf::Vector2f(50, 40), m_Engine_ref, PLAYER_BATTLE_TYPE));
    m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_DEATH);
    m_entitesPtr->getObject("PLAYER_BATTLE")->setScale(5);

    m_entitesPtr->addEntity("PLAYER_BATTLE_1", new Player(pPlayerIdleTexture, sf::Vector2f(800, 400), sf::Vector2f(50, 40), m_Engine_ref, PLAYER_BATTLE_TYPE));
    m_entitesPtr->getObject("PLAYER_BATTLE_1")->setAnimationState(PLAYER_ANIMATION_IDLE);
    m_entitesPtr->getObject("PLAYER_BATTLE_1")->setScale(5);

    //if(m_numberEnemies){

    //}
}

void Battle_Scene::cleanupData() 
{
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        delete *it;
    }
    m_buttonList.clear();
}
