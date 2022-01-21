#pragma once
#include "../objects/object.h"
#include "inputtypes.h"
#include <iostream>
/**  
* Klasa implementujaca design pattern Command sluzy do obslugi pobierania inputu i przekazywania go do update w ktorym wykonujemy poruszanie
*/
class Command
{
private:
    
public:
    virtual ~Command(){

    }
    /**
     * Metoda wykonuje polecenie
     * \param obj wskaznik na obiekt
     */
    virtual void execute(Object* obj){
    }
};

class MoveUpCommand: public Command 
{
private:
public:
    ~MoveUpCommand(){

    }
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */
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
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */
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
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */
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
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */
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
    /**
     * Metoda wykonuje polecenie poruszania
     * \param obj wskaznik na obiekt
     */
    void execute(Object *obj)
    {
        obj->setMoveState(NO_INPUT);
    }
};
