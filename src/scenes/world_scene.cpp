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
}

void World_Scene::initData(){
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "Run.png");
    m_entitesPtr->addEntity("PLAYER", new Player(pPlayerTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 50),m_Engine_ref));
    if (pPlayerTexture != nullptr)
    {
        m_entitesPtr->getObject("PLAYER")->setTexture(pPlayerTexture);
    }
    testmap = new Tilemap();
    std::shared_ptr<sf::Texture> pdirt = ResourceManager::acquireTexture(ASSETS_PATH + "dirt.png");
    testmap->addTerrain(pdirt,true);
    std::shared_ptr<sf::Texture> ptest = ResourceManager::acquireTexture(ASSETS_PATH + "test.png");
    testmap->addTerrain(ptest, true);
    testmap->initMap();
    std::cout<<"SIZE_TEXTURE_PTR"<<testmap->m_terrainPtr.size()<<"\n";
    std::cout<<"SIZE_TILES_SIZE"<<testmap->m_tiles.size()<<"\n";

    ResourceManager::cleanUpOrphans();
}

int World_Scene::processEvents(TimeStep deltatime)
{
    Command* recvCommand = m_inputhandler->handleInput();
    if(recvCommand){
    recvCommand->execute(m_entitesPtr->getObject("PLAYER"));
    }
    m_entitesPtr->processEvents(deltatime);
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
    testmap->draw(*m_Engine_ref->m_window);
    m_entitesPtr->draw((*m_Engine_ref->m_window));
}

void World_Scene::cleanupData(){

}
