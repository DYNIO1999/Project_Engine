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
/**
 *  Klasa options
 */
class OptionsScene :public Scene
{
private:
    sf::Sprite m_backgroundSprite;
    sf::Sprite m_optionsSprite;
    sf::Vector2f m_mousePosition;
    std::vector<Button*> m_buttonList;

    sf::Music optionMenuMusic;

    /**
     * @brief Metoda zapisujace opcje
     *
     */
    void saveOptions();
    /**
     * @brief Metoda wczytajaca opcje
     *
     */
    void loadOptions();
    /**
     * @brief Metoda inicujaca  dane
     *
     */
    void initData();
    /**
     * @brief Metoda czyszczaca dane
     *
     */
    void cleanUp();

public:
    /**
     * @brief Konstruktor sceny opcji
     *
     * @param engine_ref wskaznik na silnik gry
     */
    OptionsScene(Engine *engine_ref);
    /**
     *  Destruktor sceny opcji
     */
    ~OptionsScene();
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
     * @brief Metoda wejscia
     *
     */
    void input() override;
};
