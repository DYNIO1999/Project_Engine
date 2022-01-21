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
/**
 *  Klasa sceny menu
 */
class MainMenuScene: public Scene
{
private:
    /**
     *  Obiekt Sprite
     */
    sf::Sprite m_backgroundSprite;
    /**
     *  Pozycja myszki
     */
    sf::Vector2f m_mousePosition;
    /**
     *  Vektor wskaznik na przyciski
     */
    std::vector<Button*> m_buttonList;
    /**
     *  Obiekt Sprite
     */
    sf::Sprite m_warSprite;
    /**
     *  Obiekt Music
     */
    sf::Music mainMenuMusic;

    /**
     * @brief Inicjuje date
     * 
     */
    void initData();
    /**
     * @brief Czysci date
     * 
     */
    void cleanUp();
public:
    /**
     * @brief Konstruktor klasy
     * 
     * @param engine_ref Wskaznik na silnik gry
     */
    MainMenuScene(Engine *engine_ref);
    /**
     *  Destruktor klasy menu
     */
    ~MainMenuScene();
    /**
     * @brief Metoda aktualizujaca 
     * 
     * @param deltatime deltatime
     * @return int 
     */
    int processEvents(TimeStep deltatime) override;
    /**
     * @brief Metoda rysujaca
     * 
     * @param deltatime deltatime
     */
    void draw(TimeStep deltatime) override;
    /**
     *  Metoda wejscia
     */
    void input() override;
    /**
     *  Metoda inicujaca zapisane dane
     */
    void initGameSaveData();
};

