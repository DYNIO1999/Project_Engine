#include "main_menu_scene.h"
#include "../scenes/world_scene.h"
#include "../scenes/options_scene.h"

MainMenuScene::MainMenuScene(Engine *engine_ref)
{
    m_Engine_ref = engine_ref;
    initData();
}

MainMenuScene::~MainMenuScene() 
{
    cleanUp();
}

void MainMenuScene::initData()
{
    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);

    std::shared_ptr<sf::Texture> backgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "menu.png");
    m_backgroundSprite.setTexture(*backgroundTexture);
    m_backgroundSprite.setPosition(0,0);

    std::shared_ptr<sf::Texture> warTexture = ResourceManager::acquireTexture(ASSETS_PATH + "war.png");
    m_warSprite.setTexture(*warTexture);
    m_warSprite.setPosition(m_Engine_ref->m_window->getSize().x / 2 - 365.f, 100);

    std::shared_ptr<sf::Font>
        menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");

    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(0, 0, 0, 200);
    tempColors.hoverColor = sf::Color(20, 20, 20, 200);
    tempColors.idleColor = sf::Color(5, 46, 21, 200);

    int buttonwidth = 500;
    int buttonheight = 120;
    int xpos = m_Engine_ref->m_window->getSize().x / 2 - buttonwidth / 2;

    Button *playButton = new Button();
    playButton->initButton(xpos, 300, buttonwidth, buttonheight, *menuFont, "PLAY", tempColors, sf::Vector2f(0, -24));

    Button *continueButton = new Button();
    continueButton->initButton(xpos, 450, buttonwidth, buttonheight, *menuFont, "CONTINUE", tempColors, sf::Vector2f(0, -24));

    Button *optionsButton = new Button();
    optionsButton->initButton(xpos, 600, buttonwidth, buttonheight, *menuFont, "OPTIONS", tempColors, sf::Vector2f(0, -24));

    Button *exitButton = new Button();
    exitButton->initButton(xpos, 750, buttonwidth, buttonheight, *menuFont, "EXIT", tempColors, sf::Vector2f(0, -24));

    m_buttonList.push_back(playButton);
    m_buttonList.push_back(continueButton);
    m_buttonList.push_back(optionsButton);
    m_buttonList.push_back(exitButton);
    
}

void MainMenuScene::cleanUp() 
{
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        delete *it;
    }
    m_buttonList.clear();
}

int MainMenuScene::processEvents(TimeStep deltatime){
    bool check = false;
    for(int i=0;i<((int)m_buttonList.size());i++){
        check = m_buttonList[i]->ButtonUpdate();
        if(check==true){
            if(i==MENU_BUTTON_PLAY){
                check=false;
                initGameSaveData();
                m_Engine_ref->m_scene_manager->changeScene(new World_Scene(m_Engine_ref));
                return 0;
            }
            else if (i==MENU_BUTTON_CONTINUE)
            {
                check = false;
                return 0;
            }else if(i==MENU_BUTTON_OPTIONS){
                check = false;
                std::cout<<"ADD OPTIONS"<<'\n';
                m_Engine_ref->m_scene_manager->pushScene(new OptionsScene(m_Engine_ref));
                std::cout << "HERE" << '\n';
                return 0;
            }else{
                check = false;
                m_Engine_ref->m_scene_manager->popScene();
                return 0;
            }
            
        }
    }
    return 0;
}

void MainMenuScene::draw(TimeStep deltatime) 
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    m_Engine_ref->m_window->draw(m_backgroundSprite);
    m_Engine_ref->m_window->draw(m_warSprite);
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);
    }
}

void MainMenuScene::input() 
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonInput(m_mousePosition,*m_Engine_ref);
    }
}

void MainMenuScene::initGameSaveData() 
{
    m_Engine_ref->m_gameSaveData.initStartData();
}

