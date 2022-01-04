#include "core.h"
#include <iostream>
#include <fstream>

Engine::Engine(){
    m_window =nullptr;
    m_video_mode =nullptr;
    m_lasttime.m_time=0.0f;
    m_scene_manager = new SceneManager(this);
    m_primitives_render = new PrimitiveRenderer();
    isMusic =false;
}   
Engine::~Engine(){

}     
void Engine::run(){
    initWindow();
    mainLoop();
    cleanUp();

}

void Engine::mainLoop(){
    sf::Clock clock;
    while (m_window->isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        timestep = time - m_lasttime.m_time;
        m_lasttime = time;
        proccessEvents(timestep);
        draw(timestep);
    }
}

void Engine::initWindow(){

//checkScreenModes();
loadConfig();
m_window = new sf::RenderWindow;
m_video_mode = new sf::VideoMode;
m_video_mode->width=m_engine_config.getWindowWidth();
m_video_mode->height = m_engine_config.getWindowHeight();

if(m_engine_config.isFullscreen()){
    m_window->create(m_video_mode->getFullscreenModes()[0], "DEngine", sf::Style::Fullscreen);
}else{
    m_window->create(*m_video_mode,"DEngine");
}
m_window->setFramerateLimit(60);
ImGui::SFML::Init(*m_window);
///////////////


if(m_engine_config.getEngineMode()==ENGINE_DEMO){
    m_scene_manager->pushScene(new Engine_Demo(this));
}
else if (m_engine_config.getEngineMode() == ENGINE_GAME)
{
    m_scene_manager->pushScene(new MainMenuScene(this));
}
}

void Engine::proccessEvents(TimeStep deltatime){
    while (m_window->pollEvent(event))
    {
        
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
        {
            if (!m_engine_config.isFullscreen()){
            setFullScreen(true);
            }else{
                changeWinSize(1600, 900);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            if (m_engine_config.getWindowWidth() != 1600 && m_engine_config.getWindowHeight() != 900){
            changeWinSize(1600, 900);
            }else{
            changeWinSize(1000, 1000);
            }
        }
        if(!m_scene_manager->m_Scene_Stack.empty()){
        m_scene_manager->inputScene();
        }
    }
    if (m_scene_manager->m_Scene_Stack.empty())
    {
        m_window->close();
    }
    if(!m_scene_manager->m_Scene_Stack.empty()){
    m_scene_manager->processScene();
    }
}
void Engine::draw(TimeStep deltatime)
{
    if(!m_scene_manager->m_Scene_Stack.empty()){
    m_scene_manager->drawScene();
    }
    m_window->display();
}

void Engine::cleanUp(){
    m_primitives_render->cleanUp();
    std::cout << "Clearing whole Engine!" << '\n';
    ImGui::SFML::Shutdown();
    delete m_window;
    delete m_video_mode;
    delete m_scene_manager;
    m_scene_manager=nullptr;
    m_window = nullptr;
    m_video_mode= nullptr;
}

void Engine::changeWinSize(unsigned int width, unsigned int height){
    m_engine_config.setFullscreen(false);
    m_engine_config.setWindowWidth(width);
    m_engine_config.setWindowHeight(height);
    m_window->create(sf::VideoMode(width, height), "DEngine");
    saveConfig();
}
void Engine::setFullScreen(bool fullscreen){
    m_engine_config.setFullscreen(true);
    m_window->create(m_video_mode->getFullscreenModes()[0], "DEngine", sf::Style::Fullscreen);
    saveConfig();
}
void Engine::checkScreenModes(){
    modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); i++)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    }
}
void Engine::loadConfig()
{
    std::ifstream config_load;
    config_load.open("../config/EngineConfig.json");
    if (!config_load)
    {
        std::cout << "Couldnt open!";
        exit(EXIT_FAILURE);
    }
    nlohmann::json config_json;
    config_load >> config_json;

    m_engine_config.setEngineMode(config_json["EngineMode"]);

    if(config_json["FullscreenAllowed"]==1){
        m_engine_config.setFullscreen(true);
    }else{
        m_engine_config.setFullscreen(false);
    }
    m_engine_config.setWindowWidth(config_json["Window_Width"]);
    m_engine_config.setWindowHeight(config_json["Window_Height"]);
    if (config_json["SoundON"] == 1)
    {
        m_engine_config.setSound(true);
    }
    else
    {
        m_engine_config.setSound(false);
    }

    config_load.close();
}
void Engine::saveConfig()
{
    std::ifstream config_load;
    config_load.open("../config/EngineConfig.json");
    if (!config_load)
    {
        std::cout << "Couldnt open!";
        exit(EXIT_FAILURE);
    }
    nlohmann::json config_json;
    config_load >> config_json;
    config_load.close();
    config_json["EngineMode"] = m_engine_config.getEngineMode();
    
    if(m_engine_config.isFullscreen()){
        config_json["FullscreenAllowed"] =1;
    }else{
        config_json["FullscreenAllowed"] =0;
    }
    config_json["Window_Width"] =m_engine_config.getWindowWidth();
    config_json["Window_Height"] = m_engine_config.getWindowHeight();
    
    if (m_engine_config.isSound())
    {
        config_json["SoundON"] = 1;
    }
    else
    {
        config_json["SoundON"] = 0;
    }
    std::ofstream saving_file;
    saving_file.open("../config/EngineConfig.json");
    if (!saving_file)
    {
        std::cout << "Couldnt open!";
        exit(EXIT_FAILURE);
    }
    saving_file<<config_json;
    saving_file.close();
}