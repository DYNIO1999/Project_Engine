#pragma once
#include "../objects/object.h"
#include "inputtypes.h"
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
        obj->setMoveState(MOVE_UP);
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
        obj->setMoveState(MOVE_DOWN);
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
        obj->setMoveState(MOVE_LEFT);
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
        obj->setMoveState(MOVE_RIGHT);
    }
};
class NoInputCommand : public Command
{
private:
public:
    ~NoInputCommand()
    {
    }
    void execute(Object *obj)
    {
        obj->setMoveState(NO_INPUT);
    }
};
