#include "options_scene.h"
#include <fstream>

OptionsScene::OptionsScene(Engine *engine_ref) 
{
    m_Engine_ref = engine_ref;
    initData();
}

OptionsScene::~OptionsScene() 
{
    cleanUp();
}

void OptionsScene::initData()
{
    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);

    std::shared_ptr<sf::Texture> backgroundTexture = ResourceManager::acquireTexture(ASSETS_PATH + "testback.png");
    m_backgroundSprite.setTexture(*backgroundTexture);
    m_backgroundSprite.setPosition(0, 0);

    std::shared_ptr<sf::Texture> optionsTexture = ResourceManager::acquireTexture(ASSETS_PATH + "options.png");
    m_optionsSprite.setTexture(*optionsTexture);
    m_optionsSprite.setPosition(m_Engine_ref->m_window->getSize().x / 2 - 225.f, 100);

    std::shared_ptr<sf::Font> menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");

    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(70, 70, 70, 200);
    tempColors.hoverColor = sf::Color(20, 20, 20, 200);
    tempColors.idleColor = sf::Color(150, 150, 150, 200);

    int buttonwidth = 400;
    int buttonheight = 75;
    int buttonheight2 =100;
    int xpos = m_Engine_ref->m_window->getSize().x / 2 - buttonwidth / 2;
    int endxpos = m_Engine_ref->m_window->getSize().x;
    int endypos = m_Engine_ref->m_window->getSize().y;
    Button *soundONButton = new Button();
    soundONButton->initButton(xpos-(buttonwidth/2), 300, buttonwidth, buttonheight, *menuFont, "SOUND ON", tempColors);

    Button *soundOFFButton = new Button();
    soundOFFButton->initButton(xpos + (buttonwidth / 2), 300, buttonwidth, buttonheight, *menuFont, "SOUND OFF", tempColors);

    Button *backButton = new Button();
    backButton->initButton(endxpos-buttonwidth, endypos-buttonheight2, buttonwidth, buttonheight2, *menuFont, "BACK", tempColors);

    m_buttonList.push_back(soundONButton);
    m_buttonList.push_back(soundOFFButton);
    m_buttonList.push_back(backButton);
}

void OptionsScene::cleanUp()
{
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        delete *it;
    }
    m_buttonList.clear();
}

int OptionsScene::processEvents(TimeStep deltatime) 
{
    bool check = false;
    for (int i = 0; i < ((int)m_buttonList.size()); i++)
    {
        check= m_buttonList[i]->ButtonUpdate();
        if (check == true)
        {
            if (i == OPTIONS_BUTTON_SOUND_ON)
            {
                check = false;
                m_Engine_ref->m_engine_config.setSound(true);
                saveOptions();
                std::cout << "SOUND ON!" << '\n';
                return 0;
            }
            else if (i == OPTIONS_BUTTON_SOUND_OFF)
            {
                check = false;
                m_Engine_ref->m_engine_config.setSound(false);
                saveOptions();
                std::cout << "SOUND OFF!" << '\n';
                return 0;
            }
            else
            {
                std::cout << "BACK" << std::endl;
                check = false;
                m_Engine_ref->m_scene_manager->popScene();
                return 0;
            }
        }
    }
    return 0;
}

void OptionsScene::draw(TimeStep deltatime) 
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    m_Engine_ref->m_window->draw(m_backgroundSprite);
    m_Engine_ref->m_window->draw(m_optionsSprite);
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);
    }
}

void OptionsScene::input() 
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonInput(m_mousePosition,*m_Engine_ref);
    }
    }

void OptionsScene::saveOptions() 
{
    std::ifstream config_load;
    config_load.open("../config/EngineConfig.json");
    if (!config_load)
    {
        std::cout << "Couldnt open!";
        exit(EXIT_FAILURE);
    }
    nlohmann::json config_json;
    config_load >> config_json;
    config_load.close();
    config_json["EngineMode"] = m_Engine_ref->m_engine_config.getEngineMode();

    if (m_Engine_ref->m_engine_config.isFullscreen())
    {
        config_json["FullscreenAllowed"] = 1;
    }
    else
    {
        config_json["FullscreenAllowed"] = 0;
    }
    config_json["Window_Width"] = m_Engine_ref->m_engine_config.getWindowWidth();
    config_json["Window_Height"] = m_Engine_ref->m_engine_config.getWindowHeight();

    if (m_Engine_ref->m_engine_config.isSound())
    {
        config_json["SoundON"] = 1;
    }
    else
    {
        config_json["SoundON"] = 0;
    }

    std::ofstream saving_file;
    saving_file.open("../config/EngineConfig.json");
    if (!saving_file)
    {
        std::cout << "Couldnt open!";
        exit(EXIT_FAILURE);
    }
    saving_file << config_json;
    saving_file.close();
}

void OptionsScene::loadOptions() 
{
    
}
