#pragma once
#include "scene.h"
#include "../gui/buttonGUI.h"
#include <vector>

enum OPTIONS_BUTTON_TYPES
{
    OPTIONS_BUTTON_SOUND_ON,
    OPTIONS_BUTTON_SOUND_OFF,
    OPTIONS_BUTTON_BACK,
};

class Button;

class OptionsScene :public Scene
{
private:
    sf::Sprite m_backgroundSprite;
    sf::Sprite m_optionsSprite;
    sf::Vector2f m_mousePosition;
    std::vector<Button*> m_buttonList;

    sf::Music optionMenuMusic;

    void saveOptions();
    void loadOptions();

    void initData();
    void cleanUp();

public:                                                         
    OptionsScene(Engine *engine_ref);
    ~OptionsScene();
    int processEvents(TimeStep deltatime) override;
    void draw(TimeStep deltatime) override;
    void input() override;
};
