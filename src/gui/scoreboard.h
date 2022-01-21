#pragma once
#include "../core/core.h"

class Scoreboard
{   
public:
    /**
     * Konstruktor klasy scoreboard
     */
    Scoreboard(){
    }
    /**
     * Destruktor klasy scoreboard
     */
    ~Scoreboard(){

    }
    /**
     * Metoda inicujaca scoreboard
     * \param engine_ref referencja do silnika
     */
    void InitScoreBoard(Engine *engine_ref)
    {
        m_EnginePtr = engine_ref;
        m_ScoreBoardText.setFont(*ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf"));
        m_ScoreBoardText.setFillColor(sf::Color::White);
        m_ScoreBoardText.setCharacterSize(40);
        m_ScoreBoardText.setScale(sf::Vector2f(1.2, 1.2));
        m_ScoreBoardText.setOutlineColor(sf::Color::Black);
        m_ScoreBoardText.setOutlineThickness(1.f);
        m_ScoreBoardText.setLetterSpacing(2.f);
        m_ScoreBoardText.setFillColor(sf::Color::Red);

    }
    /**
     * Metoda ustawiajaca pozycje scoreboard
     * \param pos pozycja 
     */
    void SetScorboardPosition(sf::Vector2f pos)
    {   m_pos=pos;
        m_ScoreBoardText.setPosition(pos);
    }
    /**
     * Metoda ustawiajaca punkty
     * \param x o ile punktow
     */
    void SetScore(int x = 0)
    {
        m_Score = x;
    }
    /**
     * Metoda obniza punkty
     * \param x o ile punktow
     */
    void DecreaseScore(int x){
        m_Score = m_Score - x;
    }
    /**
     * Metoda dodaje punkty
     * \param x ile punktow
     */
    void AddScore(int x)
    {
        m_Score = m_Score + x;
    }
    /**
     * Metoda podaje aktualne punkty
     */
    int GetScore()
    {
        return m_Score;
    }
    /**
     * Metoda aktualizuje scoreboard
     */
    void Update()
    {
        std::string temp = std::to_string(m_Score);
        temp = temp + m_MaxScore;
        m_ScoreBoardText.setString(temp);
        m_ScoreBoardText.setPosition(m_pos);
    }
    /**
     * Metoda rysuje scoreboard
     * \param window referencja do obiektu okna
     */
    void Draw(sf::RenderWindow &window)
    {
        window.draw(m_ScoreBoardText);
    }
    /**
     * Metoda ustawia max punktow
     * \param x ilosc punktow do zodbycia maksymalnie
     */
    void SetMaxScore(int x)
    {
        m_MaxScore = "|" + std::to_string(x);
    }
    /**
     * Metoda ustawia rozmiar czcionki
     */
    void setTextSize(float size){
        m_ScoreBoardText.setCharacterSize(size);
    }
private:
    /**
     * Wskaznik na silnk gry
     */
    Engine* m_EnginePtr;
    int m_Score;
    /**Zmiennna SFML text**/
    sf::Text m_ScoreBoardText;
    /**Zmienna string przetrzymuje max score**/
    std::string m_MaxScore;
    /**
     * Wektor pozycji 
     */
    sf::Vector2f m_pos;
};
