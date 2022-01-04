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

    bool check = false;
    for (int i = 0; i < ((int)m_buttonList.size()); i++)
    {
        check = m_buttonList[i]->ButtonUpdate();
        if (check == true)
        {
            if (i == TOWN_BUTTON_ADD_ATTACK)
            {
                if (m_Engine_ref->m_gameSaveData.getPlayerExperience()>=50){
                m_Engine_ref->m_gameSaveData.setPlayerExperience(m_Engine_ref->m_gameSaveData.getPlayerExperience() - 50);
                m_Engine_ref->m_gameSaveData.setPlayerAttack(m_Engine_ref->m_gameSaveData.getPlayerAttack()+10);
                }
                check = false;
                return 0;
            }
            else if (i == TOWN_BUTTON_ADD_HEALTH)
            {
                if (m_Engine_ref->m_gameSaveData.getPlayerExperience()>=50){
                m_Engine_ref->m_gameSaveData.setPlayerExperience(m_Engine_ref->m_gameSaveData.getPlayerExperience() - 50);
                m_Engine_ref->m_gameSaveData.setPlayerHealth(m_Engine_ref->m_gameSaveData.getPlayerHealth() + 10);
                }
                check = false;
                return 0;
            }
            else if (i == TOWN_BUTTON_SAVE)
            {
                m_Engine_ref->m_gameSaveData.saveData();
                check = false;
                return 0;
            }
            else
            {
                check = false;
                if (m_Engine_ref->m_engine_config.isSound())
                {
                    m_Engine_ref->isMusic = true;
                }
                m_Engine_ref->m_scene_manager->popScene();
                return 0;
            }
        }
    }

    experienceStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerExperience());
    healthStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerHealth());
    attackStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerAttack());

    experienceStats.Update();
    healthStats.Update();
    attackStats.Update();

    m_entitesPtr->processEvents(deltatime);
    return 0;
}
void Town_Scene::draw(TimeStep deltatime)
{
    sf::Clock testclock;

    m_Engine_ref->m_window->clear(sf::Color::White);
    
    /*
    ImGui::Begin("Welcome Town_Scene");
    if (ImGui::Button("Close Town scene"))
    {
        m_Engine_ref->m_scene_manager->popScene();
        ImGui::End();
        return;
    }
    ImGui::End();
    */
    m_Engine_ref->m_window->draw(background_sprite);
    m_Engine_ref->m_window->draw(m_inventorySprite);
    m_Engine_ref->m_window->draw(m_attackText);
    m_Engine_ref->m_window->draw(m_healthText);
    m_Engine_ref->m_window->draw(m_experienceText);

    experienceStats.Draw((*m_Engine_ref->m_window));
    healthStats.Draw((*m_Engine_ref->m_window));
    attackStats.Draw((*m_Engine_ref->m_window));

    m_entitesPtr->draw((*m_Engine_ref->m_window));

    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);
    }
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


    Button* attackbutton = new Button();
    Button *healthbutton = new Button();
    Button *saveButton = new Button();
    Button *exitButton = new Button();

    attackbutton->initButton(735, 375, 72, 72, *menuFont, "+10", tempColors);
    healthbutton->initButton(735, 555, 72, 72, *menuFont, "+10", tempColors);


    attackbutton->setTextSize(20);
    attackbutton->setPosition(sf::Vector2f(0, -15));

    healthbutton->setTextSize(20);
    healthbutton->setPosition(sf::Vector2f(0, -15));


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

    
    saveButton->initButton(1000, m_Engine_ref->m_window->getSize().y/2-100,400,100, *menuFont, "Save", tempColors);
    saveButton->setTextSize(20);
    saveButton->setPosition(sf::Vector2f(0, -15));

    exitButton->initButton(1000, m_Engine_ref->m_window->getSize().y-110, 400, 100, *menuFont, "Exit", tempColors);
    exitButton->setTextSize(20);
    exitButton->setPosition(sf::Vector2f(0, -15));

    m_buttonList.push_back(attackbutton);
    m_buttonList.push_back(healthbutton);
    m_buttonList.push_back(saveButton);
    m_buttonList.push_back(exitButton);

    m_experienceText.setFont(*ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf"));
    m_experienceText.setFillColor(sf::Color::White);
    m_experienceText.setCharacterSize(25);
    m_experienceText.setScale(sf::Vector2f(1.2, 1.2));
    m_experienceText.setOutlineColor(sf::Color::Black);
    m_experienceText.setOutlineThickness(1.f);
    m_experienceText.setLetterSpacing(2.f);
    m_experienceText.setFillColor(sf::Color::Red);
    m_experienceText.setString("Exp:");
    m_experienceText.setPosition(sf::Vector2f(490, 300));

    experienceStats.InitScoreBoard(m_Engine_ref);
    experienceStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerExperience());
    experienceStats.SetScorboardPosition(sf::Vector2f(650, 300));
    experienceStats.setTextSize(25);

    attackStats.InitScoreBoard(m_Engine_ref);
    attackStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerAttack());
    attackStats.SetScorboardPosition(sf::Vector2f(600, 470));
    attackStats.setTextSize(25);


    healthStats.InitScoreBoard(m_Engine_ref);
    healthStats.SetScore(m_Engine_ref->m_gameSaveData.getPlayerHealth());
    healthStats.SetScorboardPosition(sf::Vector2f(600, 650));
    healthStats.setTextSize(25);

    townMusic.openFromFile(ASSETS_SOUNDS_PATH + "town.ogg");
    townMusic.setLoop(true);
    townMusic.setVolume(20);
    if (m_Engine_ref->m_engine_config.isSound())
    {
        townMusic.play();
    }
}

void Town_Scene::input()
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonInput(m_mousePosition, *m_Engine_ref);
    }
}

void Town_Scene::cleanUp()
{
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        delete *it;
    }
    m_buttonList.clear();
}