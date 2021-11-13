#pragma once
#include <map>
#include <iostream>
#include <string>
#include "../objects/primitive.h"

class PrimitiveRenderer
{
private:

public:
    PrimitiveRenderer(){
    }
    ~PrimitiveRenderer();
    std::map<std::string,Object*> m_primitves;
    void addPrimitive(std::string key, Object* new_primtive){
        int size=0;
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++)
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
            m_primitves.insert({key+"_"+std::to_string(0), new_primtive});
        }else{
            m_primitves.insert({key+"_"+std::to_string(size++),new_primtive});
        }
    }
    void deletePrimitive(std::string key){
        delete m_primitves.find(key)->second;
        m_primitves.erase(m_primitves.find(key));
    }
    void cleanUp(){
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++)
        {
            if (it->second != nullptr)
            {
                delete (it->second);
            }
        }
        m_primitves.clear();
    }
    Object* getObject(std::string key){
        return (m_primitves.count(key)) ? m_primitves.find(key)->second : nullptr;
    }
    void PrintObjects(){
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++)
        {
            std::cout<<it->first<<'\n';
        }
    }
    void processEvents(TimeStep dt)
    {
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++)
        {
            
            int check = it->second->processEvents(dt);
            if(check==DESTORY_OBJECT_STATE){
                delete it->second;
                m_primitves.erase(it);
            }
        }
    }

    void draw(sf::RenderWindow &win_ref)
    {
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++)
        {
            it->second->draw(win_ref);
        }
    }
    /*const char** getKeys(){
        //SKONCZYC JUTRO
        unsigned int size = m_primitves.size();
        if(size>=1){
        char* arr= new char[size];
        int i=0;
        for (auto it = m_primitves.begin(); it != m_primitves.end(); it++){
            arr[i] = new const char[it->first.length()];
            arr[i] = it->first.c_str();
            i++;
        }
        return arr;
        }else{
            return nullptr;
        }
    }*/
    /*int getSize(){
        return m_primitves.size();
    }*/
};




