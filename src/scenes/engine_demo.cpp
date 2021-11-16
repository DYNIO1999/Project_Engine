#include "engine_demo.h"
#include "../renderer/primitiveRenderer.h"
#include "../objects/player.h"
#include "../resource/resource_manager.h"
#include <string>

int Engine_Demo::processEvents(TimeStep deltatime) 
{
    return 0;
}
void Engine_Demo::draw(TimeStep deltatime)
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    sf::Time test;
    ImGui::SFML::Update((*m_Engine_ref->m_window), m_Engine_ref->m_engineClock.restart());
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
        m_Engine_ref->m_primitives_render->getObject("LINE_0")->translate(sf::Vector2f(50, 50));
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
        if (m_Engine_ref->m_primitives_render->getObject("TRIANGLE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("TRIANGLE_0")->setColor(test);
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
        if (m_Engine_ref->m_primitives_render->getObject("LINE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("LINE_0")->setPosition(sf::Vector2f(pos[0], pos[1]), m_Engine_ref->m_primitives_render->getObject("LINE_0")->getPosEndPoint());
        }
    }
    if (ImGui::SliderFloat2("POS2", pos1, 0, 1280))
    {
        if (m_Engine_ref->m_primitives_render->getObject("LINE_0"))
        {
            m_Engine_ref->m_primitives_render->getObject("LINE_0")->setPosition(m_Engine_ref->m_primitives_render->getObject("LINE_0")->getPosStartPoint(), sf::Vector2f(pos1[0], pos1[1]));
        }
    }
    ImGui::End();
    //###BitmapTesting
    /*BitmapHandler1.createBitmap(100, 100, sf::Color::Blue);
    BitmapHandler1.savetoFile(ASSETS_PATH+"test.png");
    BitmapHandler2.createBitmap(100, 100, sf::Color::Red);
    BitmapHandler2.copyBitmap(BitmapHandler1.getBitmap());
    BitmapHandler2.setPixel(1,1,sf::Color::Magenta);
    BitmapHandler2.savetoFile(ASSETS_PATH+"test2.png");
    sf::RectangleShape testShape;
    testShape.setPosition(sf::Vector2f(100,100));
    testShape.setSize(sf::Vector2f(100, 100));
    sf::Texture testTexture;
    testTexture.loadFromImage(BitmapHandler1.getBitmap(), sf::IntRect{0,0,100,100});
    testShape.setTexture(&testTexture);
    
    m_Engine_ref->m_window->draw(testShape);
    */
    //###BitmapEndTesting
    m_Engine_ref->m_primitives_render->draw(*m_Engine_ref->m_window);
    ImGui::SFML::Render(*m_Engine_ref->m_window);
};

void Engine_Demo::initData()
{
    counter = 0;
    /*
    std::shared_ptr<sf::Texture> pPlayerTexture = ResourceManager::acquireTexture(ASSETS_PATH + "portal.png");
    if(pPlayerTexture!=nullptr){
        std::cout<<"I am here";
        m_Engine_ref->m_entity_manager->getObject("PLAYER")->setTexture(pPlayerTexture);
    }
    ResourceManager::cleanUpOrphans();*/

    m_Engine_ref->m_primitives_render->addPrimitive("RECT", new Primitive(PRIMITIVE_QUAD, sf::Vector2f(500, 500), sf::Vector2f(100, 100), sf::Color::Yellow));
    m_Engine_ref->m_primitives_render->addPrimitive("TRIANGLE", new Primitive(PRIMITIVE_TRIANGLE, sf::Vector2f(200, 300), sf::Vector2f(100, 100), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("CIRCLE", new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(500, 500), 50, sf::Color::Magenta, CIRCLE_DEFAULT_ALGORITHM));

    std::vector<sf::Vector2f> arr = {
        sf::Vector2f(50, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 50),
        sf::Vector2f(100, 100),
        sf::Vector2f(100, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(50, 100),
        sf::Vector2f(200, 50),
    };
    m_Engine_ref->m_primitives_render->addPrimitive("POLYGON", new Primitive(PRIMITIVE_POLYGON, arr, sf::Color::Blue, LINE_NAIVE_ALGORITHM));

    m_Engine_ref->m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(100, 100), sf::Vector2f(200, 200), sf::Color::Red, LINE_NAIVE_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("CIRCLE", new Primitive(PRIMITIVE_CIRCLE, sf::Vector2f(500, 500), 50, sf::Color::Magenta, CIRCLE_SYM4_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("ELLIPSE", new Primitive(PRIMITIVE_ELLIPSE, sf::Vector2f(800, 400), 100, 50, sf::Color::Black, ELLIPSE_DEFAULT_ALGORITHM));
    m_Engine_ref->m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 400), sf::Vector2f(0, 0), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 450), sf::Vector2f(0, 0), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("POINT", new Primitive(PRIMITIVE_POINT, sf::Vector2f(800, 350), sf::Vector2f(0, 0), sf::Color::Red));
    m_Engine_ref->m_primitives_render->addPrimitive("LINE", new Primitive(PRIMITIVE_LINE, sf::Vector2f(100, 100), sf::Vector2f(200, 200), sf::Color::Red, LINE_NAIVE_ALGORITHM));
    m_Engine_ref->m_primitives_render->getObject("LINE_1")->setThickness(1);
    m_Engine_ref->m_primitives_render->getObject("ELLIPSE_0")->setThickness(1);
    m_Engine_ref->m_primitives_render->getObject("CIRCLE_0")->setThickness(1);
    //InitImGui Data
    vec4f[0] = 300;
    vec4f[1] = 300;
    vec4f[2] = 500;
    vec4f[3] = 500;
}