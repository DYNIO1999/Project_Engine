#pragma once
#include "../tilemap/tiletypes.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "../json.hpp"

class TileMapEditor
{
private:

public:
    TileMapEditor(){
        m_gridSize =50.f;
        m_tileSelector.setSize(sf::Vector2f(m_gridSize, m_gridSize));
        m_tileSelector.setFillColor(sf::Color::Transparent);
        m_tileSelector.setOutlineThickness(1.f);
        m_tileSelector.setOutlineColor(sf::Color::Red);

        m_map.resize(TILE_MAP_SIZE, std::vector<int>(TILE_MAP_SIZE,0));

        for(int i=0;i<TILE_MAP_SIZE;i++){
            for (int j = 0; j < TILE_MAP_SIZE; j++)
            {
                m_map[i].push_back(0);
            }
        }
        m_pressed_button_left = false;
        m_pressed_button_right = false;
    }

    ~TileMapEditor(){
    
    }
    void editInput(sf::Event& event){
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Num9)
            {
                saveMap();
            }
            if (event.key.code == sf::Keyboard::Num8)
            {
                loadMap();
            }
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                m_pressed_button_left = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
            m_pressed_button_left = false;
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                m_pressed_button_right = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
            m_pressed_button_right = false;
        }
    }
    void editMap(sf::RenderWindow& window){
        float end_x = TILE_MAP_SIZE * m_gridSize;
        float end_y = TILE_MAP_SIZE * m_gridSize;
        m_mousePosWindow = sf::Mouse::getPosition(window);
        m_mousePosView = window.mapPixelToCoords(m_mousePosWindow);
        if(m_mousePosView.x> 0 && m_mousePosView.x<end_x){
            m_mousePosGrid.x = m_mousePosView.x / ((int)m_gridSize);
        }
        if(m_mousePosView.y >0 && m_mousePosView.y<end_y){
            m_mousePosGrid.y = m_mousePosView.y / ((int)m_gridSize);
        }

        if (m_pressed_button_left)
        {
            if (m_map[m_mousePosGrid.x][m_mousePosGrid.y] < NUMBER_OF_TILES)
            {
                m_map[m_mousePosGrid.x][m_mousePosGrid.y]++;
                m_pressed_button_left = false;
            }
            else
            {
                m_map[m_mousePosGrid.x][m_mousePosGrid.y] = 0;
                m_pressed_button_left = false;
            }
        }
        if (m_pressed_button_right)
        {
            if (m_map[m_mousePosGrid.x][m_mousePosGrid.y] >0 && m_map[m_mousePosGrid.x][m_mousePosGrid.y] < NUMBER_OF_TILES)
            {
                m_map[m_mousePosGrid.x][m_mousePosGrid.y]--;
                m_pressed_button_right = false;
            }
        }
        m_tileSelector.setPosition(m_mousePosGrid.x * m_gridSize, m_mousePosGrid.y * m_gridSize);
    }
    
    void drawTileSelector(sf::RenderWindow& window){
        window.draw(m_tileSelector);
    }
    void saveMap(){
        std::ofstream tilemap_saving;
        tilemap_saving.open("../gamedata/tilemap.json");
        if (!tilemap_saving)
        {
            std::cout << "Couldnt open!";
            exit(EXIT_FAILURE);
        }
        nlohmann::json tilemap_json;
        for (int i = 0; i < TILE_MAP_SIZE; i++)
        {
            for (int j = 0; j < TILE_MAP_SIZE; j++)
            {
                tilemap_json[i][j]=m_map[i][j];
            }
        }
        tilemap_saving << tilemap_json;
        tilemap_saving.close();
    }
    void loadMap(){
        std::ifstream tilemap_load;
        tilemap_load.open("../gamedata/tilemap.json");
        if (!tilemap_load)
        {
            std::cout << "Couldnt open!";
            exit(EXIT_FAILURE);
        }
        nlohmann::json tilemap_json;
        tilemap_load >> tilemap_json;
        tilemap_load.close();
        for (int i = 0; i < TILE_MAP_SIZE; i++)
        {
            for (int j = 0; j < TILE_MAP_SIZE; j++)
            {
                m_map[i][j] =tilemap_json[i][j];
            }
        }
    }
    std::vector<std::vector<int>>& getMap(){
        return m_map;
    }
    std::vector<std::vector<int>> m_map;

    sf::Vector2i m_mousePosWindow;
    sf::Vector2f m_mousePosView;
    sf::Vector2u m_mousePosGrid;
    sf::RectangleShape m_tileSelector;
    float m_gridSize;
    bool m_pressed_button_left;
    bool m_pressed_button_right;
};

