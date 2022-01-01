#pragma once
#include <map>
#include <string>
#include "timestep.h"
#include "../objects/object.h"

/**  
* Klasa odpowiadajaca za obiekty w grze
*/
class EntityList
{
private:

public:
    EntityList(){

    }
    ~EntityList(){
        
    }

    void addEntity(std::string key, Object* obj){
        m_entities.insert(std::pair<std::string, Object*>(key, obj));
    }
    void removeEntity(std::string key)
    {
        delete m_entities.find(key)->second;
        m_entities.erase(m_entities.find(key));
    }
    Object *getObject(std::string key)
    {
        return (m_entities.count(key)) ? m_entities.find(key)->second : nullptr;
    }


    void cleanUp(){
        std::cout<<"Cleaning data of entities"<<'\n';

        for(auto it = m_entities.begin();it!=m_entities.end();it++){
            std::cout<<it->first<<'\n';
            delete it->second;
        }
        m_entities.clear();
    }
    void printObjectsNames(){
        std::cout << "LIST OF OBJECTS"<< '\n';
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            std::cout << it->first << '\n';
        }
    }

    /**  
    * Metoda aktualizujaca istniejace obiekty
    */
    void processEvents(TimeStep dt){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            int check = it->second->processEvents(dt);
            if (check == DESTORY_OBJECT_STATE)
            {
                delete it->second;
                m_entities.erase(it);
            }
        }   
    }
    /**  
    * Metoda renderujaca obiekty
    */
    void draw(sf::RenderWindow& win_ref){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->draw(win_ref);
        }
    }
    public:
    std::map<std::string,Object*> m_entities;
    private:
};
