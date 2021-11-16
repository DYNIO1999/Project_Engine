#pragma once
#include <map>
#include <string>
#include "timestep.h"
#include "../objects/object.h"

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
        for(auto it = m_entities.begin();it!=m_entities.end();it++){
            delete(it->second);
        }
        m_entities.clear();
    }


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

    void draw(sf::RenderWindow& win_ref){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->draw(win_ref);
        }
    }
    private:
    std::map<std::string,Object*> m_entities;
};
