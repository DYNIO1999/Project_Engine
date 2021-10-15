#include "core.h"

using namespace DEngine;
Engine::Engine(){
    m_window =nullptr;
    m_video_mode =nullptr;
    m_lasttime.m_time=0.0f;
    counter=0;
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
        float time =clock.getElapsedTime().asSeconds();
        TimeStep timestep = time- m_lasttime.m_time;
        m_lasttime = time;
        //std::cout << timestep.m_time << '\n';
        proccessEvents(timestep);
        draw(timestep);
    }
}

void Engine::initWindow(){
// Start
checkScreenModes();

m_window = new sf::RenderWindow;
m_video_mode = new sf::VideoMode;
m_video_mode->width=SCREEN_WIDTH;
m_video_mode->height=SCREEN_HEIGHT;

m_window->create(*m_video_mode,"DEngine");
m_window->setFramerateLimit(60);
ImGui::SFML::Init(*m_window);


}
void Engine::proccessEvents(TimeStep deltatime){
    sf::Event event;
    ImGui::SFML::ProcessEvent(event);
    while (m_window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_window->close();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
            setFullScreen(true);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            changeWinSize(modes[1].width, modes[1].height, modes[1].bitsPerPixel);
        }
    }
    
}
void Engine::draw(TimeStep deltatime)
{
    m_window->clear(sf::Color::Black);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    sf::Time test;
    //test.m_microseconds = deltatime.m_time * 1000000;
    //ImGui::SFML::Update((*m_window), test.asSeconds());
    ImGui::SFML::Update((*m_window),testclock.restart());
    ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text."); // Display some text (you can use a format strings too)

    if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
   
    ImGui::Begin("Hello,"); // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is"); // Display some text (you can use a format strings too)
    ImGui::End();
    m_window->draw(shape);
    ImGui::SFML::Render(*m_window);
    m_window->display();
}

void Engine::cleanUp(){
    std::cout << "Clearing Data!" << '\n';
    ImGui::SFML::Shutdown();
    delete m_window;
    delete m_video_mode;
    m_window = nullptr;
    m_video_mode= nullptr;
}

void Engine::changeWinSize(unsigned int modewidth, unsigned int modeheight, unsigned bitsPerPixel){
    m_window->create(sf::VideoMode(modewidth, modeheight, bitsPerPixel), "DEngine");
}
void Engine::setFullScreen(bool fullscreen){
    m_window->create(sf::VideoMode(modes[0].width, modes[0].height, modes[0].bitsPerPixel), "DEngine", sf::Style::Fullscreen);
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