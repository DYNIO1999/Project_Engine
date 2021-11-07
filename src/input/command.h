#pragma once
#include "../objects/object.h"
#include <iostream>
class Command
{
private:
    
public:
    virtual ~Command(){

    }
    virtual void execute(Object* obj){
        
    }
};

class MoveUpCommand: public Command 
{
private:
public:
    ~MoveUpCommand(){

    }
    void execute(Object* obj)
    {

        //std::cout << "MOVING UP" << std::endl;
        float y =obj->getPos().y -10;
        obj->setPosition(sf::Vector2f(obj->getPos().x , y));
    }
};

class MoveDownCommand : public Command
{
private:
public:
    ~MoveDownCommand()
    {
    }
    void execute(Object* obj)
    {
        std::cout<<"MOVING DOWN"<<std::endl;
    }
};
class MoveLeftCommand : public Command
{
private:
public:
    ~MoveLeftCommand()
    {
    }
    void execute(Object* obj)
    {
        std::cout << "MOVING LEFT" << std::endl;
    }
};

class MoveRightCommand : public Command
{
private:
public:
    ~MoveRightCommand()
    {
    }
    void execute(Object* obj)
    {
        std::cout << "MOVING RIGHT" << std::endl;
    }
};
