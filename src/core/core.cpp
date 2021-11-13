#include "core.h"
#include <iostream>
#include <fstream>

Engine::Engine(){
    m_window =nullptr;
    m_video_mode =nullptr;
    m_lasttime.m_time=0.0f;
    counter=0;
    m_scene_manager = new SceneManager(this);
    m_entity_manager = new EntityList();
    m_primitives_render = new PrimitiveRenderer();
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
    m_entity_manager->addEntity("PLAYER", new Player(sf::Vector2f(100, 100), sf::Vector2f(100, 100)));
    sf::Clock clock;
    m_primitives_render->addPrimitive("RECT",new Primitive(PRIMITIVE_QUAD, sf::Vector2f(500, 500), sf::Vector2f(100, 100), sf::Color::Yellow));
    m_primitives_render->addPrimitive("TRIANGLE",new Primitive(PRIMITIVE_TRIANGLE, sf::Vector2f(200, 300), sf::Vector2f(100, 100), sf::Color::Red));
    m_primitives_render->addPrimitive("CIRCLE",new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(500, 500),50,sf::Color::Magenta,CIRCLE_DEFAULT_ALGORITHM));

    std::vector<sf::Vector2f> arr = {sf::Vector2f(50,50),
                                     sf::Vector2f(100,50),
                                     sf::Vector2f(100,50),
                                     sf::Vector2f(100,100),
                                     sf::Vector2f(100,100),
                                     sf::Vector2f(50,100),
                                     sf::Vector2f(50,100),
                                     sf::Vector2f(200,50),
                                    };
    m_primitives_render->addPrimitive("POLYGON", new Primitive(PRIMITIVE_POLYGON,arr,sf::Color::Blue,LINE_NAIVE_ALGORITHM));

    m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(100,100),sf::Vector2f(200,200),sf::Color::Red,LINE_NAIVE_ALGORITHM));
    m_primitives_render->addPrimitive("CIRCLE", new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(500, 500), 50, sf::Color::Magenta, CIRCLE_SYM4_ALGORITHM));
    m_primitives_render->addPrimitive("ELLIPSE", new Primitive(PRIMITIVE_ELLIPSE, sf::Vector2f(800,400),100,50,sf::Color::Black,ELLIPSE_DEFAULT_ALGORITHM));
    m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 400), sf::Vector2f(0, 0), sf::Color::Red));
    m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 450), sf::Vector2f(0, 0), sf::Color::Red));
    m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 350), sf::Vector2f(0, 0), sf::Color::Red));
    m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(100, 100), sf::Vector2f(200, 200), sf::Color::Red, LINE_NAIVE_ALGORITHM));
    m_primitives_render->getObject("LINE_1")->setThickness(5);
    m_primitives_render->getObject("ELLIPSE_0")->setThickness(1);
    m_primitives_render->getObject("CIRCLE_0")->setThickness(1);
    //InitImGui Data
    vec4f[0] = 300;
    vec4f[1]=300;
    vec4f[2]=500;
    vec4f[3]=500;
    while (m_window->isOpen()){
        float time =clock.getElapsedTime().asSeconds();
        TimeStep timestep = time- m_lasttime.m_time;
        m_lasttime = time;
        proccessEvents(timestep);
        draw(timestep);
    }
}

void Engine::initWindow(){
// Start
checkScreenModes();
//JSON
/*nlohmann::json item;
item["Core"]["TicksPerSecond"] =1000;
std::ofstream config_stream_engine;
config_stream_engine.open("../config/EngineConfig.json");
if (!config_stream_engine)
{
    std::cout << "Couldnt open!";
    return;
}
config_stream_engine << item.dump(4);
config_stream_engine.close();
*/

/*std::ifstream config_load;
config_load.open("../config/EngineConfig.json");
if(!config_load){
    std::cout<<"Couldnt open!";
    return;
}

nlohmann::json config_json;
config_load >> config_json;
std::cout << config_json["TicksPerSecond"] << '\n';
config_json["TicksPerSecond"] = 1000;
std::cout << config_json["TicksPerSecond"]<<'\n';

config_load.close();*/
//JSON

m_window = new sf::RenderWindow;
m_video_mode = new sf::VideoMode;
m_video_mode->width=SCREEN_WIDTH;
m_video_mode->height=SCREEN_HEIGHT;

m_window->create(*m_video_mode,"DEngine");
m_window->setFramerateLimit(60);
ImGui::SFML::Init(*m_window);
m_input_handler = new InputHandler(this->m_window);
}

void Engine::proccessEvents(TimeStep deltatime){
    m_scene_manager->m_Scene_Stack.back()->processEvents();
    
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        m_input_handler->handleInput(m_entity_manager->getObject("PLAYER_0"));
    }
    
    m_entity_manager->processEvents(deltatime);
}
void Engine::draw(TimeStep deltatime)
{
    m_window->clear(sf::Color::White);
    sf::Time test;
    ImGui::SFML::Update((*m_window),testclock.restart());
    ImGui::Begin("Hello, world!"); // 

    ImGui::Text("This is some useful text."); 

   /* if (ImGui::Button("Button")){
        counter++;
        m_primitives_render->getObject("LINE_0")->scale((-1));
    }*/
    /*if (ImGui::Button("Rotate30")){
        m_primitives_render->getObject("LINE_0")->rotate(30);
    }*/
    if (ImGui::Button("Translate"))
    {
        m_primitives_render->getObject("LINE_0")->translate(sf::Vector2f(50,50));
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Text("Delta time %f", deltatime.m_time);
    ImGui::End();
   
    ImGui::Begin("Primitive Editor"); 
    if (ImGui::ColorEdit3("Triangle color", color))
    {
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color[2] * 255.f);
        if(m_primitives_render->getObject("TRIANGLE_0")){
            m_primitives_render->getObject("TRIANGLE_0")->setColor(test);
        }

     }
    if (ImGui::ColorEdit3("Circle color", color2))
    {
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color2[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color2[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color2[2] * 255.f);

    }

    if (ImGui::SliderFloat2("POS1", pos, 0, 1280))
    {
        if (m_primitives_render->getObject("LINE_0"))
        {
            m_primitives_render->getObject("LINE_0")->setPosition(sf::Vector2f(pos[0], pos[1]), m_primitives_render->getObject("LINE_0")->getPosEndPoint());
        }
    }
    if (ImGui::SliderFloat2("POS2", pos1,0, 1280))
    {
        if (m_primitives_render->getObject("LINE_0"))
        {
            m_primitives_render->getObject("LINE_0")->setPosition(m_primitives_render->getObject("LINE_0")->getPosStartPoint(), sf::Vector2f(pos1[0], pos1[1]));
        }
    }
    ImGui::End();
    
    m_entity_manager->draw(*m_window);
    m_primitives_render->draw(*m_window);
    ImGui::SFML::Render(*m_window);
    m_window->display();
}

void Engine::cleanUp(){
    // Clean Up add Objects and primitves clean up
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