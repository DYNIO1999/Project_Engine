#include "buttonGUI.h"

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string text, Button_Colors& buttoncolors) 
{
    m_buttonColors = buttoncolors;
    m_buttonShape.setPosition(sf::Vector2f(x, y));
    m_buttonShape.setSize(sf::Vector2f(width, height));
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setOutlineColor(sf::Color::Black);
    m_buttonFont = font;
    m_buttonText.setFont(m_buttonFont);
    m_buttonText.setString(text);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setCharacterSize(40);
    m_buttonText.setScale(sf::Vector2f(1.2, 1.2));
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1.f);
    m_buttonText.setLetterSpacing(2.f);
    m_buttonText.setPosition(m_buttonShape.getPosition().x + (m_buttonShape.getGlobalBounds().width / 2.f) - (m_buttonText.getGlobalBounds().width / 2.f),
                             m_buttonShape.getPosition().y + (m_buttonShape.getGlobalBounds().height / 2.f) - (m_buttonText.getGlobalBounds().height / 2.f) - 12.5);
    m_buttonShape.setFillColor(m_buttonColors.idleColor);
    m_buttonState = BUTTON_IDLE;
    buttonclicked.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH+"button.ogg"));
    buttonclicked.setVolume(50);
}

Button::Button(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors  &buttoncolors, sf::Vector2f offset)
{
    m_buttonColors = buttoncolors;
    m_buttonShape.setPosition(sf::Vector2f(x, y));
    m_buttonShape.setSize(sf::Vector2f(width, height));
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setOutlineColor(sf::Color::Black);
    m_buttonFont = font;
    m_buttonText.setFont(m_buttonFont);
    m_buttonText.setString(text);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setCharacterSize(40);
    m_buttonText.setScale(sf::Vector2f(1.2, 1.2));
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1.f);
    m_buttonText.setLetterSpacing(2.f);
    m_buttonText.setPosition(m_buttonShape.getPosition().x + (m_buttonShape.getGlobalBounds().width / 2.f) - (m_buttonText.getGlobalBounds().width / 2.f)-offset.x,
                             m_buttonShape.getPosition().y + (m_buttonShape.getGlobalBounds().height / 2.f) - (m_buttonText.getGlobalBounds().height / 2.f) - offset.y);
    m_buttonShape.setFillColor(m_buttonColors.idleColor);
    m_buttonState = BUTTON_IDLE;

    buttonclicked.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH + "button.ogg"));
    buttonclicked.setVolume(50);

}
Button::~Button() 
{
    
}

void Button::ButtonInput(sf::Vector2f mousepos, Engine &engineref)
{
    m_buttonState = BUTTON_IDLE;
    if (m_buttonShape.getGlobalBounds().contains(mousepos))
    {
        m_buttonState = BUTTON_HOVER;
        if (engineref.event.mouseButton.button == sf::Mouse::Left)
        {
            if (engineref.event.type == sf::Event::MouseButtonPressed){
                
                m_buttonState = BUTTON_PRESSED;
                if(engineref.m_engine_config.isSound()){
                buttonclicked.play();
                }
            }
        }
    }
}

void Button::ButtonInput(sf::Vector2f mousepos) 
{
    m_buttonState = BUTTON_IDLE;
    if (m_buttonShape.getGlobalBounds().contains(mousepos))
    {
        m_buttonState = BUTTON_HOVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_buttonState = BUTTON_PRESSED;
            buttonclicked.play();
            return;
        }
    }
}

bool Button::ButtonUpdate() 
{
    if (m_buttonState == BUTTON_IDLE)
    {
        m_buttonShape.setFillColor(m_buttonColors.idleColor);
        return false;
    }
    else if (m_buttonState == BUTTON_HOVER)
    {
        m_buttonShape.setFillColor(m_buttonColors.hoverColor);
        return false;
    }
    else if (m_buttonState == BUTTON_PRESSED)
    {
        m_buttonShape.setFillColor(m_buttonColors.pressedColor);
        m_buttonState = BUTTON_IDLE;
        return true;
    }
    return false;
}

void Button::ButtonDraw(sf::RenderWindow& window) 
{

    window.draw(m_buttonShape);
    window.draw(m_buttonText);
}

void Button::initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors) 
{
    m_buttonColors = buttoncolors;
    m_buttonShape.setPosition(sf::Vector2f(x, y));
    m_buttonShape.setSize(sf::Vector2f(width, height));
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setOutlineColor(sf::Color::Black);
    m_buttonFont = font;
    m_buttonText.setFont(m_buttonFont);
    m_buttonText.setString(text);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setCharacterSize(40);
    m_buttonText.setScale(sf::Vector2f(1.2, 1.2));
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1.f);
    m_buttonText.setLetterSpacing(2.f);
    m_buttonText.setPosition(m_buttonShape.getPosition().x + (m_buttonShape.getGlobalBounds().width / 2.f) - (m_buttonText.getGlobalBounds().width / 2.f),
                             m_buttonShape.getPosition().y + (m_buttonShape.getGlobalBounds().height / 2.f) - (m_buttonText.getGlobalBounds().height / 2.f) - 12.5);
    m_buttonShape.setFillColor(m_buttonColors.idleColor);
    m_buttonState = BUTTON_IDLE;
    buttonclicked.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH + "button.ogg"));
    buttonclicked.setVolume(50);
}
void Button::initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors, sf::Vector2f offset)
{
    m_buttonColors = buttoncolors;
    m_buttonShape.setPosition(sf::Vector2f(x, y));
    m_buttonShape.setSize(sf::Vector2f(width, height));
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setOutlineColor(sf::Color::Black);
    m_buttonFont = font;
    m_buttonText.setFont(m_buttonFont);
    m_buttonText.setString(text);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setCharacterSize(40);
    m_buttonText.setScale(sf::Vector2f(1.2, 1.2));
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1.f);
    m_buttonText.setLetterSpacing(2.f);
    m_buttonText.setPosition(m_buttonShape.getPosition().x + (m_buttonShape.getGlobalBounds().width / 2.f) - (m_buttonText.getGlobalBounds().width / 2.f) - offset.x,
                             m_buttonShape.getPosition().y + (m_buttonShape.getGlobalBounds().height / 2.f) - (m_buttonText.getGlobalBounds().height / 2.f) - offset.y);
    m_buttonShape.setFillColor(m_buttonColors.idleColor);
    m_buttonState = BUTTON_IDLE;
    buttonclicked.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH+"button.ogg"));
    buttonclicked.setVolume(50);
}

Button::Button() 
{
    
}
void Button::setTextSize(float size)
{
    m_buttonText.setCharacterSize(size);
}

void Button::setPosition(sf::Vector2f pos)
{
m_buttonText.setPosition(m_buttonShape.getPosition().x + (m_buttonShape.getGlobalBounds().width / 2.f) - (m_buttonText.getGlobalBounds().width / 2.f)-pos.x,
                         m_buttonShape.getPosition().y + (m_buttonShape.getGlobalBounds().height / 2.f) - (m_buttonText.getGlobalBounds().height / 2.f) - pos.y);
}