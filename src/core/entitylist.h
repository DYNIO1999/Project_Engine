#pragma once
#include <map>
#include <string>
#include "../objects/object.h"

class EntityList
{
private:

public:
    EntityList(){

    }
    ~EntityList(){
        
    }

    std::map<std::string,Object*> m_entities;
    void addEntity(std::string key, Object* obj){
        m_entities.insert({key,obj});
    }
    //void removeEntity(std::string key);
    //Object* findEntity(std::string key);
    void cleanUp(){
        for(auto it = m_entities.begin();it!=m_entities.end();it++){
            if(it->second!=nullptr){
                delete(it->second);
            }
        }
        m_entities.clear();
    }
    void processEvents(){

    }
    void draw(sf::RenderWindow& win_ref){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->draw(win_ref);
        }
    }
};
