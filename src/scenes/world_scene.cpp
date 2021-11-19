#include "../core/core.h"
#include "world_scene.h"
#include "../objects/player.h"

World_Scene::World_Scene(Engine *engine_ref)
{
    this->m_Engine_ref = engine_ref;
    m_entitesPtr =  new EntityList();
    m_inputhandler = new InputHandler();
    initData();
}
World_Scene::~World_Scene(){
    delete testmap;
    delete m_entitesPtr;
    delete m_inputhandler;
    delete m_mapeditor;
}

void World_Scene::initData(){
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "player_attack1.png");
    m_entitesPtr->addEntity("PLAYER", new Player(pPlayerTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 50),m_Engine_ref));
    if (pPlayerTexture != nullptr)
    {
        m_entitesPtr->getObject("PLAYER")->setTexture(pPlayerTexture);
    }
    std::shared_ptr<sf::Texture> pdirt = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "grass.png");
    std::shared_ptr<sf::Texture> pbank1 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank1.png");
    std::shared_ptr<sf::Texture> pbank2 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank2.png");
    std::shared_ptr<sf::Texture> pbank3 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank3.png");
    std::shared_ptr<sf::Texture> pbank4 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank4.png");
    std::shared_ptr<sf::Texture> pbank5 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank5.png");
    std::shared_ptr<sf::Texture> pbank6 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank6.png");
    std::shared_ptr<sf::Texture> pbank7 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank7.png");
    std::shared_ptr<sf::Texture> pbank8 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank8.png");
    std::shared_ptr<sf::Texture> pbank9 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank9.png");
    std::shared_ptr<sf::Texture> pbank10 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank10.png");
    std::shared_ptr<sf::Texture> pbank11 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank11.png");
    std::shared_ptr<sf::Texture> pbank12 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "bank12.png");
    std::shared_ptr<sf::Texture> pwater = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "water.png");
    
    m_mapeditor = new TileMapEditor();
    testmap = new Tilemap(m_mapeditor->getMap());
    testmap->addTerrain(pdirt,true);
    testmap->addTerrain(pbank1, true);
    testmap->addTerrain(pbank2, true);
    testmap->addTerrain(pbank3, true);
    testmap->addTerrain(pbank4, true);
    testmap->addTerrain(pbank5, true);
    testmap->addTerrain(pbank6, true);
    testmap->addTerrain(pbank7, true);
    testmap->addTerrain(pbank8, true);
    testmap->addTerrain(pbank9, true);
    testmap->addTerrain(pbank10, true);
    testmap->addTerrain(pbank11, true);
    testmap->addTerrain(pbank12, true);
    testmap->addTerrain(pwater, true);
    testmap->initMap();
    std::cout<<"SIZE_TEXTURE_PTR"<<testmap->m_terrainPtr.size()<<"\n";
    std::cout<<"SIZE_TILES_SIZE"<<testmap->m_tiles.size()<<"\n";
    
    ResourceManager::cleanUpOrphans();
}

int World_Scene::processEvents(TimeStep deltatime)
{
    m_entitesPtr->processEvents(deltatime);
    testmap->processEvents(m_mapeditor->getMap());
    return 0;
}
void World_Scene::draw(TimeStep deltatime)
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    sf::Texture text;
    //text.loadFromFile(ASSETS_PATH+"testback.png");
    //sf::Sprite background;
    //background.setTexture(text);
    //background.setPosition(sf::Vector2f(0,0));
    //m_Engine_ref->m_window->draw(background);
    testmap->draw(*m_Engine_ref->m_window, m_Engine_ref->m_window->getView());
    m_entitesPtr->draw((*m_Engine_ref->m_window));
    m_mapeditor->drawTileSelector(*m_Engine_ref->m_window);
}
void World_Scene::input(){
    m_mapeditor->editInput(m_Engine_ref->event);
    m_mapeditor->editMap(*m_Engine_ref->m_window);
    Command *recvCommand = m_inputhandler->handleInput();
    if (recvCommand)
    {
        recvCommand->execute(m_entitesPtr->getObject("PLAYER"));
    }
}
void World_Scene::cleanupData(){

}
