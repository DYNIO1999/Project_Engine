#pragma once 
#include "tile.h"
#include "tiletypes.h"
#include <vector>
#include <iostream>
#include "../objects/object.h"
class Tilemap
{
public:
    std::vector<Terrain*> m_terrainPtr;
    std::vector<Tile> m_tiles;
    std::vector<std::vector<int>>m_map;
public:
    /**
     * @brief Konstruktor klasy Tilemap
     *
     * @param map pobiera referencje do wektora 2D INT
     */
    Tilemap(std::vector<std::vector<int>>& map){
        m_map = map;
    }
    /**
     * @brief Destruktor klasy Tilemap
     *
     */
    ~Tilemap(){
        cleanUp();
    }
    /**
     * @brief Metoda inicujaca tilemap
     *
     */
    void initMap(){
        float temp_width =50;
        float temp_height =50;
	    for (int i = 0; i < TILE_MAP_SIZE; i++){
		    for (int j = 0; j < TILE_MAP_SIZE; j++) {
			    if (m_map[i][j] == GRASS_TILE) {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[GRASS_TILE]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if(m_map[i][j] ==BANK_TILE_1){
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_1]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_2)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_2]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_3)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_3]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_4)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_4]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_5)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_5]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_6)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_6]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_7)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_7]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_8)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_8]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_9)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_9]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_10)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_10]);
                    temp.m_gridPos = sf::Vector2i(j,i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_11)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_11]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == BANK_TILE_12)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[BANK_TILE_12]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_1)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_1]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_2)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_2]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_3)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_3]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_4)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_4]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_5)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_5]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_6)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_6]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_7)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_7]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_8)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_8]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_9)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_9]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_10)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_10]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_11)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_11]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_12)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_12]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == FOREST_TILE_13)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[FOREST_TILE_13]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
                if (m_map[i][j] == WATER_TILE)
                {
                    Tile temp(sf::Vector2f(j * temp_width, i * temp_height), sf::Vector2f(temp_width, temp_height), m_terrainPtr[WATER_TILE]);
                    temp.m_gridPos = sf::Vector2i(j, i);
                    m_tiles.push_back(temp);
                }
            }
        }
    }
    /**
     * @brief Metoda aktualizujaca tilemap
     *
     */
    void updateTileMap(){
        for(auto it = m_tiles.begin();it<m_tiles.end();it++){
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == GRASS_TILE)
            {
                it->updateTerrain(m_terrainPtr[GRASS_TILE]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_1)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_1]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_2)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_2]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_3)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_3]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_4)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_4]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_5)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_5]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_6)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_6]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_7)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_7]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_8)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_8]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_9)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_9]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_10)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_10]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_11)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_11]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == BANK_TILE_12)
            {
                it->updateTerrain(m_terrainPtr[BANK_TILE_12]);
            }
            ////
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_1)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_1]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_2)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_2]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_3)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_3]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_4)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_4]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_5)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_5]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_6)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_6]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_7)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_7]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_8)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_8]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_9)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_9]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_10)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_10]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_11)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_11]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_12)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_12]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == FOREST_TILE_13)
            {
                it->updateTerrain(m_terrainPtr[FOREST_TILE_13]);
            }
            if (m_map[it->m_gridPos.x][it->m_gridPos.y] == WATER_TILE)
            {
                it->updateTerrain(m_terrainPtr[WATER_TILE]);
            }
        }
    }
    /**
     * @brief Metoda dodajaca teren
     *
     * @param texture wskaznik na tkesture
     * @param passable czy jest mozliwe poruszanie sie po niej
     */
    void addTerrain(std::shared_ptr<sf::Texture> texture, bool passable)
    {
        Terrain* temp = new Terrain(texture,passable);
        m_terrainPtr.push_back(temp);
        temp = nullptr;
    }
    /**
     * @brief Metoda aktualizujaca
     *
     * @param map pobiera referencje do wektora 2D INT
     */
    void processEvents(std::vector<std::vector<int>>& map){
        m_map = map;
        updateTileMap();
    }
    /**
     * @brief Metoda sprawdzajaca kolizje z tilemap
     *
     * @param obj refernecja obiektu
     */
    void checkCollisionTilemap(Object& obj){

        for(auto it = m_tiles.begin();it<m_tiles.end();it++){
            if(!it->m_terrainPtr->isPassable()){
                if(obj.getBoxCollider().intersects(it->m_colisionBox)){
                sf::Vector2f temp = obj.getBoxCollider().resolve_collision_rect(it->m_colisionBox);
                obj.setPosition(obj.getPos() + temp);
                }
            }
        }
    }
    /**
     * @brief  Metoda sprawdzajaca kolizje z lasem
     *
     * @param obj refernecja obiektu
     * @return true
     * @return false
     */
    bool checkCollsionwithTilesForest(Object& obj){
        for(auto it = m_tiles.begin();it<m_tiles.end();it++){
            if (obj.getBoxCollider().intersects(it->m_colisionBox))
            {
                for (int i = FOREST_TILE_1; i <= FOREST_TILE_13;i++){
                    if (m_map[it->m_gridPos.x][it->m_gridPos.y] ==i)
                    {
                        return true;
                    }
                }
            }
        }
    return false;
    }
    /**
     * @brief Metoda rysujaca tilemap
     *
     * @param win_ref referencja okna
     * @param gameView referencja gameview 
     */
    void draw(sf::RenderWindow &win_ref, const sf::View &gameView)
    {
        for (int i = 0; i < ((int)m_tiles.size()); i++)
        {
            if ((m_tiles[i].m_pos.x >= (gameView.getCenter().x - gameView.getSize().x / 2 -50)) &&
                (m_tiles[i].m_pos.x <= (gameView.getCenter().x + gameView.getSize().x / 2+50)) && 
                (m_tiles[i].m_pos.y >= (gameView.getCenter().y - gameView.getSize().y / 2 - 50)) &&
                (m_tiles[i].m_pos.y <= (gameView.getCenter().y + gameView.getSize().y / 2 +50 )))
            {
                //std::cout<<"Tile pos"<<m_tiles[i].m_pos.x<<'\n';
                //std::cout<<"CAMERA SIZE1"<<gameView.getCenter().x - gameView.getSize().x/2<<'\n';
                //std::cout<< "CAMERA SIZE2" << gameView.getCenter().x + gameView.getSize().x/2 << '\n';

                win_ref.draw(m_tiles[i].m_vertex, m_tiles[i].m_terrainPtr->getTexture().get());
            }
        }
    }
    /**
     * @brief Metoda czyszczaca tilemap
     *
     */
    void cleanUp(){
        for (auto it = m_terrainPtr.begin(); it != m_terrainPtr.end(); it++)
        {
            delete *it;
        }
        m_terrainPtr.clear();
        m_tiles.clear();
    }
};

