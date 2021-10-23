#include "core.h"

//using namespace DEngine;
Engine::Engine(){
    m_window =nullptr;
    m_video_mode =nullptr;
    m_lasttime.m_time=0.0f;
    counter=0;
    m_scene_manager = new SceneManager(this);
    m_entity_manager = new EntityList();
}   
Engine::~Engine(){

}     
void Engine::run(){
    initWindow();
    mainLoop();
    cleanUp();

}

void Engine::mainLoop(){
    m_scene_manager->pushScene(new World_Scene);
    //obj = new Drawable(RECTANGLE, 100, 100, 100, 100, sf::Color::Green);
    //obj2 = new Drawable(200,200,sf::Color::Red,POINT); --> Point
    Object *test = new Player(sf::Vector2f(100, 100), sf::Vector2f(100, 100));
    m_entity_manager->addEntity("Player_1", test);
    sf::Clock clock;
    while (m_window->isOpen()){
        float time =clock.getElapsedTime().asSeconds();
        TimeStep timestep = time- m_lasttime.m_time;
        m_lasttime = time;
        //std::cout << timestep.m_time << '\n';
        //std::cout << "SIZE SCENE STACK" << m_scene_manager->m_Scene_Stack.size()<< std::endl;
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
    m_scene_manager->m_Scene_Stack.back()->processEvents();
    //obj->processEvents();
    //obj2->processEvents();
    
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
            //setFullScreen(true);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            //changeWinSize(modes[1].width, modes[1].height, modes[1].bitsPerPixel);
        }
    }
    
}
void Engine::draw(TimeStep deltatime)
{
    m_window->clear(sf::Color::Black);
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
    ImGui::Text("Delta time %f", deltatime.m_time);
    ImGui::End();
   
    ImGui::Begin("Primitive Editor"); // Create a window called "Hello, world!" and append into it.
    if (ImGui::ColorEdit3("Triangle color", color))
    {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color[2] * 255.f);
        //obj->setColor(test);
    }
    if (ImGui::ColorEdit3("Circle color", color2))
    {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color2[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color2[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color2[2] * 255.f);
        //obj2->setColor(test);

    }
    //ADDEEDDDDD
    //TEST
    if (ImGui::SliderFloat2("Position", pos,0,1280))
    {
        //obj->setPosition(pos[0],pos[1]);
    }
    if (ImGui::SliderFloat2("Size", size,0, 1280))
    {
        //obj->setSize(size[0], size[1]);
    }

    if (ImGui::SliderFloat2("Position", pos1, 0, 1280))
    {
        //obj2->setPosition(pos1[0], pos1[1]);
    }
    if (ImGui::SliderFloat2("Size", size1, 0, 1280))
    {
        //obj2->setSize(size1[0], size1[1]);
    }
    ImGui::End();
    
    //obj->draw(*m_window);
    //obj2->draw(*m_window);
    m_entity_manager->draw(*m_window);
    ImGui::SFML::Render(*m_window);
    m_window->display();
}

void Engine::cleanUp(){
    std::cout << "Clearing whole Engine!" << '\n';
    ImGui::SFML::Shutdown();
    delete m_window;
    delete m_video_mode;
    delete m_scene_manager;
    m_scene_manager=nullptr;
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