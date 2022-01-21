#pragma once
#include <vector>
#include "scene.h"
#include <iostream>
#include "../core/timestep.h"

/**  
* Klasa SceneManager sluzy do obslugi scen naszej gry
*/
class SceneManager{
    
    public:
    /**
     * @brief Konstruktor klasy scene manager
     * 
     * @param m_Engine_ref wskaznik na silnik gry
     */
    SceneManager(Engine* m_Engine_ref);
    /**
     *  Destruktor klasy scene manager
     */
    ~SceneManager();
    /**
     * @brief Metoda zmieniajaca scene
     *
     * @param new_scene wskaznik na nowa scene
     */
    void changeScene(Scene* new_scene);
    /**
     * @brief Metoda dodaje scene
     *
     * @param new_scene wskaznik na nowa scene
     */
    void pushScene(Scene* new_scene);

    /**
     * @brief Metoda zdejmujaca scene
     *
     */
    void popScene();
    /**
     * @brief Metoda rysujaca scene
     *
     */
    void drawScene();
    /**
     * @brief Metoda aktualizujaca scene
     *
     */
    void processScene();
    /**
     * @brief Metoda input scene
     *
     */
    void inputScene();
    /**
     * Wektor wskaznikow na sceny
     *
     */
    std::vector<Scene*> m_Scene_Stack;
    /**
     * Wskaznik na silnik gry
     *
     */
    Engine *m_Engine_ref;
    private:
};
