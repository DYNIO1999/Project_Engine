#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler
{
private:
    sf::Image m_bitmap;

public:
    BitmapHandler(){
    }
    ~BitmapHandler(){
        
    }
    void createBitmap(int width, int height, sf::Color color){
        m_bitmap.create(width, height, color);
    }
    bool loadFromFile(std::string path){
        if (m_bitmap.loadFromFile(path))
        {
            return true;
        }
        return false;
    }
    bool savetoFile(std::string path){
        if (m_bitmap.saveToFile(path))
        {
            return true;
        }
        return false;
    }
    void copyBitmap(sf::Image bitmap){
        m_bitmap.copy(bitmap, 0,0);
    }
    void setPixel(int x,int y,sf::Color color){
        m_bitmap.setPixel(x,y,color);
    }
    sf::Image& getBitmap()
    {
        return m_bitmap;
    }
};

