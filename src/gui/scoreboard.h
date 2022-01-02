#pragma once
#include "../core/core.h"

class Scoreboard
{   
public:
    Scoreboard(){
    }
    ~Scoreboard(){

    }

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
    void SetScorboardPosition(sf::Vector2f pos)
    {   m_pos=pos;
        m_ScoreBoardText.setPosition(pos);
    }
    void SetScore(int x = 0)
    {
        m_Score = x;
    }
    void DecreaseScore(int x){
        m_Score = m_Score - x;
    }
    void AddScore(int x)
    {
        m_Score = m_Score + x;
    }
    int GetScore()
    {
        return m_Score;
    }
    void Update()
    {
        std::string temp = std::to_string(m_Score);
        temp = temp + m_MaxScore;
        m_ScoreBoardText.setString(temp);
        m_ScoreBoardText.setPosition(m_pos);
    }
    void Draw(sf::RenderWindow &window)
    {
        window.draw(m_ScoreBoardText);
    }
    void SetMaxScore(int x)
    {
        m_MaxScore = "|" + std::to_string(x);
    }
    void setTextSize(float size){
        m_ScoreBoardText.setCharacterSize(size);
    }
private:
    Engine* m_EnginePtr;
    int m_Score;
    /**Zmiennna SFML text**/
    sf::Text m_ScoreBoardText;
    /**Zmienna string przetrzymuje max score**/
    std::string m_MaxScore;
    sf::Vector2f m_pos;
};
