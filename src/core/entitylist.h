#pragma once
#include <map>
#include <string>
#include "timestep.h"
#include "../objects/object.h"

/**
 * Klasa odpowiadajaca za przetrzymaywanie obiektow gry
 */
class EntityList
{
private:

public:
    /**
     * Konstruktor klasy
     * 
     */
    EntityList(){

    }
    /**
     * Destruktor klasy
     */
    ~EntityList(){
        
    }
    /**
     * Metoda dodajaca obiekt
     * \param key klucz czyli nazwa obiektu.
     * \param obj wskaznik na obiekt.
     */
    void addEntity(std::string key, Object* obj){
        m_entities.insert(std::pair<std::string, Object*>(key, obj));
    }
    /**
     * Metoda usuwajaca obiekt
     * \param key klucz czyli nazwa obiektu.
     */
    void removeEntity(std::string key)
    {
        delete m_entities.find(key)->second;
        m_entities.erase(m_entities.find(key));
    }
    /**
     * Metoda podaje obiekt
     * \param key klucz czyli nazwa obiektu.
     */
    Object *getObject(std::string key)
    {
        return (m_entities.count(key)) ? m_entities.find(key)->second : nullptr;
    }
    /**
     * Metoda usuwa obiekty
     */
    void cleanUp(){
        std::cout<<"Cleaning data of entities"<<'\n';

        for(auto it = m_entities.begin();it!=m_entities.end();it++){
            std::cout<<it->first<<'\n';
            delete it->second;
        }
        m_entities.clear();
    }
    /**
     * Metoda wyswietla obiekty
     */
    void printObjectsNames(){
        std::cout << "LIST OF OBJECTS"<< '\n';
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            std::cout << it->first << '\n';
        }
    }
    /**
     * Metoda aktualizujaca istniejace obiekty
     * \param dt deltatime
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
     * \param win_ref referncja do renderu czyli okna
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
