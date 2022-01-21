#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
class Terrain
{
private:
    bool m_isPassable;
    std::shared_ptr<sf::Texture> m_texturePtr;
public:
    /**
     * @brief Konstruktor klasy Terrain
     *
     * @param texture wskaznik na teksture
     * @param isPassable warunek czy jest mozliwe poruszanie sie po niej
     */
    Terrain(std::shared_ptr<sf::Texture> texture, bool isPassable){
        
        m_isPassable = isPassable;
        m_texturePtr = texture;
    }
    /**
     * @brief Destruktor klasy Terrain
     *
     */
    ~Terrain(){

    }
    /**
     * @brief Metoda sprawdzajaca czy dany terren jest mozliwy do przejscia
     *
     * @return true
     * @return false
     */
    bool isPassable(){
        return m_isPassable;
    }
    /**
     * @brief Metoda podajaca teksture
     *
     * @return std::shared_ptr<sf::Texture>
     */
    std::shared_ptr<sf::Texture> getTexture(){
        return m_texturePtr;
    }
    
};
