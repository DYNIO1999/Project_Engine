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
    delete m_entitesPtr;
    delete m_inputhandler;
}

void World_Scene::initData(){
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "portal.png");
    m_entitesPtr->addEntity("PLAYER", new Player(pPlayerTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 50),m_Engine_ref));
    if (pPlayerTexture != nullptr)
    {
        m_entitesPtr->getObject("PLAYER")->setTexture(pPlayerTexture);
    }
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
    m_entitesPtr->draw((*m_Engine_ref->m_window));
}

void World_Scene::cleanupData(){

}
