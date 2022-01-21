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
/**
 * Klasa button
 */
class Button
{
private:
    /**
     * Obiekt ksztaltu przycisku
     */
    sf::RectangleShape m_buttonShape;
    /**
     * Obiekt font przetrzymuje informacje typie czcionki
     */
    sf::Font m_buttonFont;
    /**
     * Obiekt przetrzymuje tekst
     */
    sf::Text m_buttonText;
    /**
     * Obiekt przetrzymuje kolory przycisku
     */
    Button_Colors m_buttonColors;
    /**
     * Obiekt przetrzymuje dzwiek przycisku
     */
    sf::Sound buttonclicked;
    /**
     * Zmienna zapisuje stan przycisku
     */
    int m_buttonState;
public:
    /**
     * Konstruktor klasy Button
     */
    Button();
    /**
     * Konstruktor klasy Button
     * \param x pozycja x przycisku
     * \param y pozycja y przycisku
     * \param width szerokosc przycisku
     * \param height wysokosc przycisku
     * \param font referencja do typu czcionki
     * \param text tekst
     * \param buttoncolors referencja do obiektu kolorow przycisku
     * \param offset offset pozycji
     */
    Button(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors, sf::Vector2f offset);
    /**
     * Konstruktor klasy Button
     * \param x pozycja x przycisku
     * \param y pozycja y przycisku
     * \param width szerokosc przycisku
     * \param height wysokosc przycisku
     * \param font referencja do typu czcionki
     * \param text tekst
     * \param buttoncolors referencja do obiektu kolorow przycisku
     */
    Button(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors);
    /**
     * Destruktor klasy Button
     */
    ~Button();
    /**
     * Metoda pobierajaca input od uzytkownika
     * \param mousepos pozycja myszki
     * \param engineref referencja do silnika gry
     */
    void ButtonInput(sf::Vector2f mousepos, Engine &engineref);
    /**
     * Metoda pobierajaca input od uzytkownika
     * \param mousepos pozycja myszki
     */
    void ButtonInput(sf::Vector2f mousepos);
    /**
     * Metoda aktualizujaca przycisk
     */
    bool ButtonUpdate();
    /**
     * Metoda rysujaca przycisk
     * \param window referencja do okna
     */
    void ButtonDraw(sf::RenderWindow& window);
    /**
     * Metoda inicujaca przycisk
     * \param x pozycja x przycisku
     * \param y pozycja y przycisku
     * \param width szerokosc przycisku
     * \param height wysokosc przycisku
     * \param font referencja do typu czcionki
     * \param text tekst
     * \param buttoncolors referencja do obiektu kolorow przycisku
     */
    void initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors);
    /**
     * Metoda ustawiajaca rozmiar czcionki
     * \param size rozmiar
     */
    void setTextSize(float size);
    /**
     * Metoda inicjujaca przycisk
     * \param x pozycja x przycisku
     * \param y pozycja y przycisku
     * \param width szerokosc przycisku
     * \param height wysokosc przycisku
     * \param font referencja do typu czcionki
     * \param text tekst
     * \param buttoncolors referencja do obiektu kolorow przycisku
     * \param offset offset pozycji
     */
    void initButton(float x, float y, float width, float height, sf::Font &font, std::string text, Button_Colors &buttoncolors, sf::Vector2f offset);
    /**
     * Metoda ustawiajaca przycisk
     * \param pos pozycja 
     */
    void setPosition(sf::Vector2f pos);
};