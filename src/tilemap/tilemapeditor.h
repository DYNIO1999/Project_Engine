#pragma once
#include "../tilemap/tiletypes.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

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

        m_map.resize(25, std::vector<int>(25,0));

        for(int i=0;i<25;i++){
            for(int j=0;j<25;j++){
                m_map[i].push_back(0);
            }
        }
        m_pressed_button = false;
    }

    ~TileMapEditor(){
    
    }
    void editInput(sf::Event& event){
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                m_pressed_button = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
            m_pressed_button = false;
        }
    }
    void editMap(sf::RenderWindow& window){
        float end_x = 25*50;
        float end_y = 25*50;
        m_mousePosWindow = sf::Mouse::getPosition(window);
        m_mousePosView = window.mapPixelToCoords(m_mousePosWindow);
        if(m_mousePosView.x> 0 && m_mousePosView.x<end_x){
            m_mousePosGrid.x = m_mousePosView.x / ((int)m_gridSize);
        }
        if(m_mousePosView.y >0 && m_mousePosView.y<end_y){
            m_mousePosGrid.y = m_mousePosView.y / ((int)m_gridSize);
        }
        
        if (m_pressed_button)
        {
            if (m_map[m_mousePosGrid.x][m_mousePosGrid.y] < NUMBER_OF_TILES)
            {
                m_map[m_mousePosGrid.x][m_mousePosGrid.y]++;
                m_pressed_button = false;
            }
            else
            {
                m_map[m_mousePosGrid.x][m_mousePosGrid.y] = 0;
                m_pressed_button = false;
            }
        }
        m_tileSelector.setPosition(m_mousePosGrid.x * m_gridSize, m_mousePosGrid.y * m_gridSize);
    }
    
    void drawTileSelector(sf::RenderWindow& window){
        window.draw(m_tileSelector);
    }
    void saveMap();
    void loadMap();
    std::vector<std::vector<int>>& getMap(){
        return m_map;
    }
    std::vector<std::vector<int>> m_map;

    sf::Vector2i m_mousePosWindow;
    sf::Vector2f m_mousePosView;
    sf::Vector2u m_mousePosGrid;
    sf::RectangleShape m_tileSelector;
    float m_gridSize;
    bool m_pressed_button;
};

