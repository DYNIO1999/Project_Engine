#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>

const std::string ASSETS_PATH = "../assets/";
const std::string ASSETS_BACKGROUND_PATH = "../assets/backgrounds/";
const std::string ASSETS_TILESET_PATH = "../assets/tilesets/";
const std::string ASSETS_FONTS_PATH = "../assets/fonts/";
const std::string ASSETS_CHARACTER_BATTLE_PATH = "../assets/char_battle/";
const std::string ASSETS_ENEMY_BATTLE_PATH = "../assets/enemies/";
const std::string ASSETS_ITEMS_PATH = "../assets/items/";
const std::string ASSETS_SOUNDS_PATH = "../assets/Music/";

/**
 * Klasa Zarzadca Zasobow
 */
class ResourceManager{
    public:
    /**
     * Metoda pobiera teksture
     * @param path sciezka do assetu
     * @return std::shared_ptr<sf::Texture> 
     */
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
    /**
     * Metoda pobiera font
     * @param path sciezka do assetu
     * @return std::shared_ptr<sf::Font> 
     */
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
    /**
     * Metoda pobiera SoundBuffer
     * @param path sciezka do assetu
     * @return std::shared_ptr<sf::SoundBuffer>
     */
    static std::shared_ptr<sf::SoundBuffer> acquireSound(const std::string &path)
    {
        const auto it = m_soundsPtr.find(path);
        if (it != m_soundsPtr.end())
        {
            return it->second;
        }
        else
        {
            auto pSound = std::make_shared<sf::SoundBuffer>();
            pSound->loadFromFile(path);
            m_soundsPtr.insert({path, pSound});
            return pSound;
        }
    }
    /**
     * @brief Metoda czyszcaca assety 
     * 
     */
    static void cleanUpOrphans(){
        for(auto it = m_texturesPtr.begin();it!=m_texturesPtr.end();  ){
            if(it->second.unique()){
                it = m_texturesPtr.erase(it);
            }else{
                it++;
            }

        }
        for (auto it = m_fonts.begin(); it != m_fonts.end();)
        {
            if (it->second.unique())
            {
                it = m_fonts.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
    private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_texturesPtr;
    static std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;
    static std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> m_soundsPtr;
};