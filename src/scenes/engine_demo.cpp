#include "engine_demo.h"
#include "../renderer/primitiveRenderer.h"
#include "../objects/player.h"
#include "../resource/resource_manager.h"
#include <string>

Engine_Demo::~Engine_Demo(){
    gameObjectsListPtr->cleanUp();
    delete gameObjectsListPtr;
    delete m_inputhandler;
    m_Engine_ref->m_primitives_render->cleanUp();
}
int Engine_Demo::processEvents(TimeStep deltatime) 
{
    gameObjectsListPtr->processEvents(deltatime);
    return 0;
}
void Engine_Demo::draw(TimeStep deltatime)
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    
    sf::Time test;
    ImGui::Begin("DEngine"); 

    ImGui::Text("This is some useful text.");

    if (ImGui::Button("Scale Line 1 by 0.5 DOWN")){
        m_Engine_ref->m_primitives_render->getObject("LINE_0")->scale((0.5));
    }
    if (ImGui::Button("Scale Line 1 by 0.5 UP"))
    {
        m_Engine_ref->m_primitives_render->getObject("LINE_0")->scale((2));
    }
    if (ImGui::Button("Translate Line 1 by vector(50,50)"))
    {
        m_Engine_ref->m_primitives_render->getObject("LINE_0")->translate(sf::Vector2f(50, 50));
    }
    ImGui::End();
    ImGui::Begin("Primitive Editor");
    if (ImGui::ColorEdit3("Triangle color", color))
    {
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color[2] * 255.f);
        if (m_Engine_ref->m_primitives_render->getObject("TRIANGLE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("TRIANGLE_0")->setColor(test);
        }
    }
    if (ImGui::ColorEdit3("Quad color", color2))
    {
        sf::Color test;
        test.r = static_cast<sf::Uint8>(color2[0] * 255.f);
        test.g = static_cast<sf::Uint8>(color2[1] * 255.f);
        test.b = static_cast<sf::Uint8>(color2[2] * 255.f);
        if (m_Engine_ref->m_primitives_render->getObject("RECT_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("RECT_0")->setColor(test);
        }
    }

    if (ImGui::SliderFloat2("LINE 1 POSITION", pos, 0, 1280))
    {
        if (m_Engine_ref->m_primitives_render->getObject("LINE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("LINE_0")->setPosition(sf::Vector2f(pos[0], pos[1]), m_Engine_ref->m_primitives_render->getObject("LINE_0")->getPosEndPoint());
        }
    }
    if (ImGui::SliderFloat2("LINE 2 POSITION", pos1, 0, 1280))
    {
        if (m_Engine_ref->m_primitives_render->getObject("LINE_1"))
        {
            m_Engine_ref->m_primitives_render->getObject("LINE_1")->setPosition(m_Engine_ref->m_primitives_render->getObject("LINE_1")->getPosStartPoint(), sf::Vector2f(pos1[0], pos1[1]));
        }
    }
    if (ImGui::SliderFloat("LINE 1 THICKNESS", &thickness, 0, 100))
    {
        if (m_Engine_ref->m_primitives_render->getObject("LINE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("LINE_0")->setThickness(thickness);
        }
    }
    ImGui::End();
    
    BitmapHandler1.createBitmap(100, 100, sf::Color::Blue);
    BitmapHandler1.savetoFile(ASSETS_PATH + "test.png");
    BitmapHandler2.createBitmap(100, 100, sf::Color::Red);
    BitmapHandler2.copyBitmap(BitmapHandler1.getBitmap());
    for(int i=0;i<100;i++){
        BitmapHandler2.setPixel(1, i, sf::Color::Black);
    }
    BitmapHandler2.savetoFile(ASSETS_PATH + "test2.png");
    sf::RectangleShape testShape;
    testShape.setPosition(sf::Vector2f(600, 100));
    testShape.setSize(sf::Vector2f(100,100));
    sf::Texture testTexture;
    testTexture.loadFromImage(BitmapHandler1.getBitmap(), sf::IntRect{0, 0, 100, 100});
    testShape.setTexture(&testTexture);
    m_Engine_ref->m_window->draw(testShape);
    gameObjectsListPtr->draw(*m_Engine_ref->m_window);
    m_Engine_ref->m_primitives_render->draw(*m_Engine_ref->m_window);
};

void Engine_Demo::initData()
{
    sf::View temp = m_Engine_ref->m_window->getView();
    temp.zoom(1.0f);
    m_Engine_ref->m_window->setView(temp);
    
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "player_attack1.png");
    ResourceManager::cleanUpOrphans();
    gameObjectsListPtr->addEntity("PLAYER", new Player(pPlayerTexture, sf::Vector2f(100, 100), sf::Vector2f(40, 40), m_Engine_ref,1));
    gameObjectsListPtr->getObject("PLAYER")->setTexture(pPlayerTexture);

    m_Engine_ref->m_primitives_render->addPrimitive("RECT", new Primitive(PRIMITIVE_QUAD, sf::Vector2f(1100, 0), sf::Vector2f(100, 100), sf::Color::Yellow));
    m_Engine_ref->m_primitives_render->addPrimitive("TRIANGLE", new Primitive(PRIMITIVE_TRIANGLE, sf::Vector2f(200, 0), sf::Vector2f(100, 100), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(300, 0), sf::Vector2f(0, 0), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("CIRCLE", new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(400, 0), 50, sf::Color::Green, CIRCLE_DEFAULT_ALGORITHM));
    
    m_Engine_ref->m_primitives_render->addPrimitive("CIRCLE", new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(600, 50), 50, sf::Color::Magenta, CIRCLE_SYM4_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("ELLIPSE", new Primitive(PRIMITIVE_ELLIPSE, sf::Vector2f(800, 100), 50,100,sf::Color::Magenta, ELLIPSE_DEFAULT_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("ELLIPSE", new Primitive(PRIMITIVE_ELLIPSE, sf::Vector2f(950, 100), 50,100,sf::Color::Magenta, ELLIPSE_SYM4_ALGORITHM));
        std::vector<sf::Vector2f>
            arr = {
        sf::Vector2f(50, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 100),
        sf::Vector2f(100, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(200, 50),
    };

    std::vector<sf::Vector2f> arr2 = {
        sf::Vector2f(50, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 100),
        sf::Vector2f(100, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(50, 50),
    };

    //Cant create that
    m_Engine_ref->m_primitives_render->addPrimitive("POLYGON", new Primitive(PRIMITIVE_POLYGON, arr, sf::Color::Blue, LINE_NAIVE_ALGORITHM));
    
    m_Engine_ref->m_primitives_render->addPrimitive("POLYGON", new Primitive(PRIMITIVE_POLYGON, arr2, sf::Color::Blue, LINE_NAIVE_ALGORITHM));

    m_Engine_ref->m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(400, 400), sf::Vector2f(600, 600), sf::Color::Blue, LINE_NAIVE_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(500, 800), sf::Vector2f(700, 800), sf::Color::Red, LINE_NAIVE_ALGORITHM));
    m_Engine_ref->m_primitives_render->getObject("LINE_1")->setThickness(10);
    //InitImGui Data
    vec4f[0] = 300;
    vec4f[1] = 300;
    vec4f[2] = 500;
    vec4f[3] = 500;
}

void Engine_Demo::input()
{
    Command *recvCommand = m_inputhandler->handleInput();
    if (recvCommand)
    {
        recvCommand->execute(gameObjectsListPtr->getObject("PLAYER"));
    }
}