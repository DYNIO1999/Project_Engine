#include "core.h"

using namespace DEngine;
Engine::Engine(){
    m_window =nullptr;
    m_video_mode =nullptr;
}   
Engine::~Engine(){

}     
void Engine::run(){
    initWindow();
    mainLoop();
    cleanUp();

}

void Engine::mainLoop(){
    while (m_window->isOpen()){
        proccessEvents();
        draw();
    }
}

void Engine::initWindow(){
// Start
m_window = new sf::RenderWindow;
m_video_mode = new sf::VideoMode;
m_video_mode->width=SCREEN_WIDTH;
m_video_mode->height=SCREEN_HEIGHT;

m_window->create(*m_video_mode,"DEngine");
m_window->setFramerateLimit(60);

}
void Engine::proccessEvents(){
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window->close();

        }
    }
    
}
void Engine::draw(){

}


void Engine::cleanUp(){
    std::cout << "Clearing Data!" << '\n';
    delete m_window;
    delete m_video_mode;
    m_window = nullptr;
    m_video_mode= nullptr;
}


