#include "../core/core.h"
#include "world_scene.h"
#include "../objects/player.h"
#include "../objects/town.h"

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
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "token_player.png");
    m_entitesPtr->addEntity("PLAYER", new Player(pPlayerTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 50),m_Engine_ref));
    if (pPlayerTexture != nullptr)
    {
        m_entitesPtr->getObject("PLAYER")->setTexture(pPlayerTexture);
    }
    std::shared_ptr<sf::Texture> ptownTexture = ResourceManager::acquireTexture(ASSETS_PATH + "token_player.png");
    m_entitesPtr->addEntity("TOWN", new Town(ptownTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 50)));

    std::shared_ptr<sf::Texture> background = ResourceManager::acquireTexture(ASSETS_PATH + "testback.png");
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
    std::shared_ptr<sf::Texture> pforest1 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest1.png");
    std::shared_ptr<sf::Texture> pforest2 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest2.png");
    std::shared_ptr<sf::Texture> pforest3 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest3.png");
    std::shared_ptr<sf::Texture> pforest4 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest4.png");
    std::shared_ptr<sf::Texture> pforest5 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest5.png");
    std::shared_ptr<sf::Texture> pforest6 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest6.png");
    std::shared_ptr<sf::Texture> pforest7 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest7.png");
    std::shared_ptr<sf::Texture> pforest8 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest8.png");
    std::shared_ptr<sf::Texture> pforest9 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest9.png");
    std::shared_ptr<sf::Texture> pforest10 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest10.png");
    std::shared_ptr<sf::Texture> pforest11 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest11.png");
    std::shared_ptr<sf::Texture> pforest12 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest12.png");
    std::shared_ptr<sf::Texture> pforest13 = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "forest13.png");
    std::shared_ptr<sf::Texture> pwater = ResourceManager::acquireTexture(ASSETS_TILESET_PATH + "water.png");
    
    background_sprite.setTexture(*background);
    background_sprite.setPosition(-300,-300);
    m_mapeditor = new TileMapEditor();
    testmap = new Tilemap(m_mapeditor->getMap());
    testmap->addTerrain(pdirt,true);
    testmap->addTerrain(pbank1, false);
    testmap->addTerrain(pbank2, false);
    testmap->addTerrain(pbank3, false);
    testmap->addTerrain(pbank4, false);
    testmap->addTerrain(pbank5, false);
    testmap->addTerrain(pbank6, false);
    testmap->addTerrain(pbank7, false);
    testmap->addTerrain(pbank8, false);
    testmap->addTerrain(pbank9, false);
    testmap->addTerrain(pbank10, false);
    testmap->addTerrain(pbank11, false);
    testmap->addTerrain(pbank12, false);
    //
    testmap->addTerrain(pforest1, true);
    testmap->addTerrain(pforest2, true);
    testmap->addTerrain(pforest3, true);
    testmap->addTerrain(pforest4, true);
    testmap->addTerrain(pforest5, true);
    testmap->addTerrain(pforest6, true);
    testmap->addTerrain(pforest7, true);
    testmap->addTerrain(pforest8, true);
    testmap->addTerrain(pforest9, true);
    testmap->addTerrain(pforest10, true);
    testmap->addTerrain(pforest11, true);
    testmap->addTerrain(pforest12, true);
    testmap->addTerrain(pforest13, true);
    testmap->addTerrain(pwater, false);
    
    testmap->initMap();
    m_mapeditor->loadMap();
    std::cout<<"SIZE_TEXTURE_PTR"<<testmap->m_terrainPtr.size()<<"\n";
    std::cout<<"SIZE_TILES_SIZE"<<testmap->m_tiles.size()<<"\n";
    
    ResourceManager::cleanUpOrphans();
}

int World_Scene::processEvents(TimeStep deltatime)
{
    m_entitesPtr->processEvents(deltatime);
    testmap->checkCollisionTilemap(*m_entitesPtr->getObject("PLAYER"));
    testmap->processEvents(m_mapeditor->getMap());
    return 0;
}
void World_Scene::draw(TimeStep deltatime)
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    m_Engine_ref->m_window->draw(background_sprite);
    //background_sprite.
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
