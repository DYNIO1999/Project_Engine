#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>
const std::string ASSETS_PATH = "../assets/";
const std::string ASSETS_TILESET_PATH = "../assets/tilesets/";
const std::string ASSETS_FONTS_PATH = "../assets/fonts/";
class ResourceManager{
    public:
    static std::shared_ptr<sf::Texture> acquireTexture(const std::string& path){
        const auto it  = m_texturesPtr.find(path);
        if(it!=m_texturesPtr.end()){
            return it->second;
        }else{
            auto pTexture = std::make_shared<sf::Texture>();
            pTexture->loadFromFile(path);
            m_texturesPtr.insert({path,pTexture});
            return pTexture;
        }
    }
    static std::shared_ptr<sf::Font> acquireFont(const std::string &path)
    {
        const auto it = m_fonts.find(path);
        if (it != m_fonts.end())
        {
            return it->second;
        }
        else
        {
            auto pFont = std::make_shared<sf::Font>();
            pFont->loadFromFile(path);
            m_fonts.insert({path, pFont});
            return pFont;
        }
    }
    static void cleanUpOrphans(){
        for(auto it = m_texturesPtr.begin();it!=m_texturesPtr.end();  ){
            if(it->second.unique()){
                it = m_texturesPtr.erase(it);
            }else{
                it++;
            }

        }
    }
    private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_texturesPtr;
    static std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;
};