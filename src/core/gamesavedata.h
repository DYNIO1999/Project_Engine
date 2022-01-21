#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

/**
 * Klasa game data
 */
class GameSaveData
{
private:
    sf::Vector2f m_playerPosMap;
    int m_wonBattles;
    float m_playerHealth;
    float m_playerAttack;
    float m_playerExperience;
    int m_currentNumberPotions;
public:
    /**
     * Konstruktor klasy gamedata
     */
    GameSaveData(){

    }
    /**
     * Destruktor klasy gamedata
     */
    ~GameSaveData(){

    }
    /**
     * Metoda inicjujaca date 
     */
    void initStartData(){
        m_playerPosMap = sf::Vector2f(900, 200);
        m_wonBattles =0;
        m_playerHealth =100;
        m_playerAttack =50;
        m_playerExperience =0;
        m_currentNumberPotions =0;
    }
    /**
     * Metoda podajaca ilosc potek
     */
    int getCurrentNumberPotions()
    {
        return m_currentNumberPotions;
    }
    /**
     * Metoda ustawiajaca ilosc potek
     * \param currentNumberPotions ilosc potek
     */
    void setCurrentNumberPotions(int currentNumberPotions)
    {
        m_currentNumberPotions = currentNumberPotions;
    }
    /**
     * Metoda podajaca pozycje gracza
     */
    sf::Vector2f getPlayerPosMap(){
        return m_playerPosMap;
    }
    /**
     * Metoda usawiajaca pozycje gracza
     * \param playerPosMap pozycja gracza
     */
    void setPlayerPosMap(sf::Vector2f playerPosMap){
        m_playerPosMap = playerPosMap;
    }
    /**
     * Metoda podajaca wygrane bitwy przez gracza
     */
    int getWonBattles(){
        return m_wonBattles;
    }
    /**
     * Metoda usawiajaca wygrane bitwy przez gracza
     * \param wonBattles wygrane bitwy
     */

    void setWonBattles(int wonBattles){
        m_wonBattles = wonBattles;
    }
    /**
     * Metoda usawiajaca aktualne zycie gracza
     * \param  playerhealth zycie gracza
     */
    void setPlayerHealth(float playerhealth){
        m_playerHealth = playerhealth;
    }
    /**
     * Metoda podajaca aktualne zycie gracza
     */
    float getPlayerHealth(){
        return m_playerHealth;
    }
    /**
     * Metoda ustawiajaca wartosc ataku gracza
     * \param  playerattack wartosc ataku
     */
    void setPlayerAttack(float playerattack)
    {
        m_playerAttack = playerattack;
    }
    /**
     * Metoda podajaca wartosc ataku gracza
     */
    float getPlayerAttack()
    {
        return m_playerAttack;
    }
    /**
     * Metoda ustawiajaca doswiadczenie gracza
     * \param  playerexperience wartosc doswiadczenia
     */

    void setPlayerExperience(float playerexperience)
    {
        m_playerExperience = playerexperience;
    }
    /**
     * Metoda podajaca doswiadczenie gracza
     */
    float getPlayerExperience()
    {
        return m_playerExperience;
    }
    /**
     * Metoda zapisujaca gamedata do json
     */
    void saveData(){
        std::ifstream data_load;
        data_load.open("../gamedata/lastsave.json");
        if (!data_load)
        {
            std::cout << "Couldnt open!";
            exit(EXIT_FAILURE);
        }
        nlohmann::json data_json;
        data_load >> data_json;
        data_load.close();

        data_json["PlayerPosX"]=m_playerPosMap.x;
        data_json["PlayerPosY"]=m_playerPosMap.y;
        data_json["WonBattles"]=m_wonBattles;
        data_json["PlayerHealth"]=m_playerHealth;
        data_json["PlayerAttack"]=m_playerAttack;
        data_json["PlayerExperience"]=m_playerExperience;
        data_json["CurrentNumberPotions"]=m_currentNumberPotions;

        std::ofstream saving_file;
        saving_file.open("../gamedata/lastsave.json");
        if (!saving_file)
        {
            std::cout << "Couldnt open!";
            exit(EXIT_FAILURE);
        }
        saving_file << data_json;
        saving_file.close();
    }
    /**
     * Metoda odczytujaca gamedata z json
     */
    void loadData(){
            std::ifstream data_load;
            data_load.open("../gamedata/lastsave.json");
            if (!data_load)
            {
                std::cout << "Couldnt open!";
                exit(EXIT_FAILURE);
            }
            nlohmann::json data_json;
            data_load >> data_json;

            m_playerPosMap.x = data_json["PlayerPosX"];
            m_playerPosMap.y =data_json["PlayerPosY"];
            m_wonBattles =data_json["WonBattles"];
            m_playerHealth =data_json["PlayerHealth"];
            m_playerAttack =data_json["PlayerAttack"];
            m_playerExperience =data_json["PlayerExperience"];
            m_currentNumberPotions = data_json["CurrentNumberPotions"];

            data_load.close();
    }
};

