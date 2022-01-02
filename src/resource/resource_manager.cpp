#include "resource_manager.h"
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> ResourceManager::m_texturesPtr;
std::unordered_map<std::string, std::shared_ptr<sf::Font>> ResourceManager::m_fonts;
std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> ResourceManager::m_soundsPtr;
