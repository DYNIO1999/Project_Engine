#pragma once 
#include "tile.h"
#include "tiletypes.h"
#include <vector>
#include <iostream>
class Tilemap
{
public:
    int m_map[5][10]{
        0,0,1,0,0,0,0,1,0,0,
        0,0,1,0,0,0,0,1,0,0,
        0,1,1,0,0,0,0,1,0,0,
        0,1,1,1,0,0,0,1,0,0,
        0,0,1,0,0,0,0,1,0,0,
    };
    std::vector<Terrain*> m_terrainPtr;
    std::vector<Tile> m_tiles;
public:
    Tilemap(){

    }
    ~Tilemap(){
        cleanUp();
    }
    void initMap(){
        float temp_width =50;
        float temp_height =50;
	    for (int i = 0; i < 5; i++){
		    for (int j = 0; j < 10; j++) {
			    if (m_map[i][j] == GRASS_TILE) {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[GRASS_TILE]);
                    m_tiles.push_back(temp);
                }
                if(m_map[i][j] ==WALL_TILE){
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[WALL_TILE]);
                    m_tiles.push_back(temp);
                }    
            }
        }
    }
    void addTerrain(std::shared_ptr<sf::Texture> texture, bool passable)
    {
        Terrain* temp = new Terrain(texture,passable);
        m_terrainPtr.push_back(temp);
        temp = nullptr;
    }  
    void processEvents(){
    }
    void draw(sf::RenderWindow& win_ref){
        for(int i=0;i<((int)m_tiles.size());i++){
            win_ref.draw(m_tiles[i].m_vertex, m_tiles[i].m_terrainPtr->getTexture().get());
        }
    }
    void cleanUp(){
        for (auto it = m_terrainPtr.begin(); it != m_terrainPtr.end(); it++)
        {
            delete *it;
        }
        m_terrainPtr.clear();
        m_tiles.clear();
    }
};

