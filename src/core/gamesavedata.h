#pragma once
#include <SFML/Graphics.hpp>
#include "../gamestats/characterstats.h"

class GameSaveData
{
private:
    sf::Vector2f m_playerPosMap;
    int m_wonBattles;

public:
    GameSaveData(){

    }
    ~GameSaveData(){

    }
    sf::Vector2f getPlayerPosMap(){

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

    void saveData(){

    }
    void loadData(){

    }
};

