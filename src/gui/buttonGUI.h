#pragma once
#include <string>
#include "../core/core.h"

enum BUTTON_STATES
{
    BUTTON_PRESSED,
    BUTTON_HOVER,
    BUTTON_IDLE,

};
struct Button_Colors{
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;
};

class Button
{
private:
    sf::RectangleShape m_buttonShape;
    sf::Font m_buttonFont;
    sf::Text m_buttonText;
    Button_Colors m_buttonColors;
    int m_buttonState;
public:
    Button();
    Button(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors, sf::Vector2f offset);

        Button(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors);
    ~Button();
    void ButtonInput(sf::Vector2f mousepos, Engine &engineref);
    void ButtonInput(sf::Vector2f mousepos);
    bool ButtonUpdate();
    void ButtonDraw(sf::RenderWindow& window);
    void initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors);
    void setTextSize(float size);
    void initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors, sf::Vector2f offset);

    void setPosition(sf::Vector2f pos);
};