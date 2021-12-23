#pragma once
#include "../gui/buttonGUI.h"
#include <vector>
#include "scene.h"


class Button;

enum MENU_BUTTON_TYPES{
    MENU_BUTTON_PLAY,
    MENU_BUTTON_CONTINUE,
    MENU_BUTTON_OPTIONS,
    MENU_BUTTON_EXIT,
};

class MainMenuScene: public Scene
{
private:
    
    sf::Sprite m_backgroundSprite;
    sf::Vector2f m_mousePosition;
    std::vector<Button*> m_buttonList;
    
    void initData();
    void cleanUp();
public:
    MainMenuScene(Engine *engine_ref);
    ~MainMenuScene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;
    void input() override;
};

