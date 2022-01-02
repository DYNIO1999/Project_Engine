#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

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
    GameSaveData(){

    }
    ~GameSaveData(){

    }
    void initStartData(){
        m_playerPosMap = sf::Vector2f(900, 200);
        m_wonBattles =0;
        m_playerHealth =100;
        m_playerAttack =50;
        m_playerExperience =0;
        m_currentNumberPotions =0;
    }
    int getCurrentNumberPotions()
    {
        return m_currentNumberPotions;
    }

    void setCurrentNumberPotions(int currentNumberPotions)
    {
        m_currentNumberPotions = currentNumberPotions;
    }

    sf::Vector2f getPlayerPosMap(){
        return m_playerPosMap;
    }
    void setPlayerPosMap(sf::Vector2f playerPosMap){
        m_playerPosMap = playerPosMap;
    }   

    int getWonBattles(){
        return m_wonBattles;
    }

    void setWonBattles(int wonBattles){
        m_wonBattles = wonBattles;
    }

    void setPlayerHealth(float playerhealth){
        m_playerHealth = playerhealth;
    }
    float getPlayerHealth(){
        return m_playerHealth;
    }

    void setPlayerAttack(float playerattack)
    {
        m_playerAttack = playerattack;
    }
    float getPlayerAttack()
    {
        return m_playerAttack;
    }

    void setPlayerExperience(float playerexperience)
    {
        m_playerExperience = playerexperience;
    }
    float getPlayerExperience()
    {
        return m_playerExperience;
    }
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

