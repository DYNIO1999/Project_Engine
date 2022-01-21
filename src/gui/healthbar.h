#pragma once
#include "../core/core.h"
/**
 * Klasa paske zycia
 */
class HealthBar
{
public:
    /**
     * Konstruktor paska zycia
     */
    HealthBar();
    /**
     * Konstruktor paska zycia
     * \param x pozcyja x
     * \param y pozycja y
     * \param sizeX rozmiar X
     * \param sizeY rozmiar Y
     */
    HealthBar(float x, float y, float sizeX, float sizeY);
    /**
     * Destruktor paska zycia
     */
    ~HealthBar();
    /**
     * Metoda inicujaca pasek zycia
     * \param x pozycja x
     * \param y pozycja y
     * \param sizeX rozmiar X
     * \param sizeY rozmiar Y
     */
    void init(float x, float y, float sizeX, float sizeY);
    /**
     * Metoda aktualizujaca pasek zycia
     * \param sizeX rozmiar X
     * \param x pozycja x
     * \param y pozycja y
     */
    void update(float sizeX, float x, float y);
    /**
     * Metoda rysujaca pasek zycia
     * \param window okno
     */
    void draw(sf::RenderWindow &window);
    /**
     * Metoda ustawiajaca rozmiar tla paska zycia
     * \param size rozmiar
     */
    void setBackBarSize(float size);
private:
    /**
     * Obiekt pasek zycia 
     */
    sf::RectangleShape m_backHPbar;
    /**
     * Obiekt pasek zycia
     */
    sf::RectangleShape m_frontHPBar;
};
