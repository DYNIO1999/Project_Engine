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
    std::map<std::string,Object*> m_entities;

    void addEntity(std::string key, Object* obj){
        int size=0;
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            std::string temp; 
            for(std::size_t i=0;i<it->first.length();i++){
                if (it->first[i]!='_'){
                    temp=temp+it->first[i];
                }else{
                    break;
                }
            }
            if(temp==key){
                size++;
            }
        }
        if(size==0){
            m_entities.insert({key + "_" + std::to_string(0), obj});
        }else{
            m_entities.insert({key + "_" + std::to_string(size++), obj});
        }
    }
    void removeEntity(std::string key)
    {
        delete m_entities.find(key)->second;
    }
    Object *getObject(std::string key)
    {
        //return (m_entities.count(key)) ? m_entities.find(key)->second : nullptr;
        return m_entities.find(key)->second;
    }


    void cleanUp(){
        for(auto it = m_entities.begin();it!=m_entities.end();it++){
            if(it->second!=nullptr){
                delete(it->second);
            }
        }
        m_entities.clear();
    }


    void processEvents(TimeStep dt){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->processEvents(dt);
        }
    }

    void draw(sf::RenderWindow& win_ref){
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->draw(win_ref);
        }
    }
};
