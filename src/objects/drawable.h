#pragma once
//#include <vector>

/*
enum PRIMITIVE_TYPE
{
    SQAURE,
    RECTANGLE,
    LINE,
    TRIANGLE,
    CIRCLE,
    POINT,
};
class Point2D{
    public:
    Point2D(){
        
    }
    ~Point2D(){}
    private:
    sf::Vertex v_point;
    sf::Vector2f pos;
    sf::Vector2f size;
    public:
    sf::Vector2f getPosition(){
        return pos;
    }
    sf::Vector2f getSize()
    {
        return size;
    }
    void setPos(sf::Vector2f pos){
        this->pos = pos;
        v_point.position=this->pos;

    }
    void setSize(sf::Vector2f size)
    {
        this->size =size;
        
    }
    void setColor(sf::Color color){
        v_point.color = color;
    }
    void draw(sf::RenderWindow& win_ref){
        win_ref.draw(&v_point, 1, sf::Points);
    }
};

class Drawable : public Static_Object 
{
public:
    Drawable(int primitivetype, int pos_x, int pos_y, int width, int height, sf::Color color)
    {
        this->m_primitivetype = primitivetype;
        this->x=pos_x;
        this->y=pos_y;
        this->m_width = width;
        this->m_height = height;
        this->m_color = color;
        //this->m_vertices_count=count;
        initPrimitive();
    }
    Drawable(int pos_x, int pos_y, sf::Color color, int primitivetype = POINT)
    {
        this->m_primitivetype = primitivetype;
        this->x = pos_x;
        this->y = pos_y;
        this->m_color = color;
        //this->m_points_count=count;
        initPrimitive();
    }

    ~Drawable() {
        if(m_circle){
            delete m_circle;
        }
        if (m_vertices){
            delete[] m_vertices;
        }
    }
    void processEvents() override{

    }
    void draw(sf::RenderWindow& win_ref) override{
        if (m_primitivetype == RECTANGLE){
            win_ref.draw(m_vertices,4 , sf::Quads);
       }
        if(m_primitivetype == TRIANGLE){
            win_ref.draw(m_vertices, 3, sf::Triangles);
        }
        if(m_primitivetype == CIRCLE){
            win_ref.draw(*m_circle);
        }
        if (m_primitivetype == POINT)
        {
            points->draw(win_ref);
        }
    }
    void initPrimitive(){
        if(m_primitivetype == POINT){
            points = new Point2D();
            points->setPos(sf::Vector2f(x,y));
            points->setColor(m_color);
        }
        if(m_primitivetype ==CIRCLE){
            m_circle = new sf::CircleShape(m_width);
            m_circle->setPosition(x,y);
            m_circle->setFillColor(m_color);
        }
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices = new sf::Vertex[4];
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;
            
            m_vertices[1].position.x = x+m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x+m_width;
            m_vertices[2].position.y = y+m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y+m_height;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }
        if(m_primitivetype == TRIANGLE){
            m_vertices = new sf::Vertex[3];
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x+(m_width/2);
            m_vertices[1].position.y = y+m_height;

            m_vertices[2].position.x = x-(m_width/2);
            m_vertices[2].position.y = y + m_height;

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
        }
    }
    void setPosition(float x, float y){
        if (m_primitivetype == RECTANGLE){
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x + m_width;
            m_vertices[2].position.y = y + m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y + m_height;
        }
        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + (m_width / 2);
            m_vertices[1].position.y = y + m_height;

            m_vertices[2].position.x = x - (m_width / 2);
            m_vertices[2].position.y = y + m_height;
        }
        if (m_primitivetype == CIRCLE)
        {
            m_circle->setPosition(x,y);
            this->x =x;
            this->y = y;
        }
    }
    void setColor(sf::Color color){
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;
        }

        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].color = color;
            m_vertices[1].color = color;
            m_vertices[2].color = color;
        }
        if (m_primitivetype == CIRCLE){
            m_circle->setFillColor(color);
        }
    }
    void setSize(float width, float height){
        m_width=width;
        m_height=height;
        if (m_primitivetype == RECTANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + m_width;
            m_vertices[1].position.y = y;

            m_vertices[2].position.x = x + m_width;
            m_vertices[2].position.y = y + m_height;

            m_vertices[3].position.x = x;
            m_vertices[3].position.y = y + m_height;
        }
        if (m_primitivetype == TRIANGLE)
        {
            m_vertices[0].position.x = x;
            m_vertices[0].position.y = y;

            m_vertices[1].position.x = x + (m_width / 2);
            m_vertices[1].position.y = y + m_height;

            m_vertices[2].position.x = x - (m_width / 2);
            m_vertices[2].position.y = y + m_height;
        }
    }
    sf::Vector2f getPos()
    {
    }
    sf::Vector2f getSize()
    {
    }
    sf::Vector2f getColor()
    {
    }
    int m_primitivetype;
    //int m_points_count;
    sf::Vertex* m_vertices;
    sf::Color m_color;
private:
    sf::CircleShape* m_circle;
    Point2D* points;
};
*/