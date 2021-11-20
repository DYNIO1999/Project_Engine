#pragma once
#include "terrain.h"
#include "../collision/boxcollider.h"
class Tile
{
private:

public:
    BoxCollider m_colisionBox;
    sf::VertexArray m_vertex;
    sf::Vector2f m_pos;
    sf::Vector2f m_size;
    Terrain* m_terrainPtr;
    sf::Vector2i m_gridPos;
    Tile(sf::Vector2f pos, sf::Vector2f size, Terrain* terrain)
    {
        m_pos = pos;
        m_size = size;
        m_terrainPtr = terrain;
        m_vertex.setPrimitiveType(sf::Quads);
        m_vertex.resize(m_size.x * m_size.y * 4);
        m_vertex[0].position = sf::Vector2f(m_pos.x, m_pos.y);
        m_vertex[1].position = sf::Vector2f(m_pos.x + m_size.x, m_pos.y);
        m_vertex[2].position = sf::Vector2f(m_pos.x + m_size.x, m_pos.y + m_size.y);
        m_vertex[3].position = sf::Vector2f(m_pos.x, m_pos.y + m_size.y);

        m_vertex[0].texCoords = sf::Vector2f(1, 1);
        m_vertex[1].texCoords = sf::Vector2f(50, 1);
        m_vertex[2].texCoords = sf::Vector2f(50, 50);
        m_vertex[3].texCoords = sf::Vector2f(1, 50);
        BoxCollider temp(m_pos.x, m_pos.y, m_size.x, m_size.y);
        m_colisionBox=temp; 
    }
    void updateTerrain(Terrain *terrain)
    {
        m_terrainPtr=terrain;
    }
    ~Tile(){

    }
};
