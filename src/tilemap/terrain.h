#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
class Terrain
{
private:
    bool m_isPassable;
    std::shared_ptr<sf::Texture> m_texturePtr;
public:
    Terrain(std::shared_ptr<sf::Texture> texture, bool isPassable){
        
        m_isPassable = isPassable;
        m_texturePtr = texture;
    }
    ~Terrain(){

    }
    std::shared_ptr<sf::Texture> getTexture(){
        return m_texturePtr;
    }
    
};
