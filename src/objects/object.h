#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../core/timestep.h"
#include "objectstates.h"
#include "../transforms/transforms.h"
#include "../collision/boxcollider.h"

#include <memory>

/**  
* Klasa nadrzedna z metodami wirtualnymi i czysto wirtualnymi sluz do osblugi obiektow
*/
class Object{
    public:
    
    /**
     * Konstruktor klasy enemy
     * \param texturePtr wskaznik na obiekt tekstury
     * \param pos pozycja
     * \param size rozmiar
     * \param enginePtr wskaznik na silnik gry
     */


    /**
     * Konstruktor klasy
     */
    Object(){}
    
    /**
     * Destruktor klasy
     */
    virtual ~Object(){}

    /**
     * Metoda aktualizujaca
     */
    virtual void processEvents(){

    }

    /**
     * Metoda aktualizujaca
     * \param dt deltatime
     */
    virtual int processEvents(TimeStep dt) =0;

    /**
     * Metoda rysujaca
     * \param win_ref referencja do okna
     */
    virtual void draw(sf::RenderWindow &win_ref) = 0;

    /**
     * Metoda ustawiajaca rozmiar
     * \param size rozmiar
     */
    virtual void setSize(sf::Vector2f size)=0;
    /**
     * Metoda ustawiajaca kolor
     * \param color obiekt kolorow
     */
    virtual void setColor(sf::Color color)=0;
    /**
     * Metoda ustawiajaca pozycje
     * \param pos pozycja
     */
    virtual void setPosition(sf::Vector2f pos)=0;
    /**
     * Metoda ustawiajaca skale
     * \param scale skala
     */
    virtual void setScale(float scale){

    }
    /**
     * Metoda ustawiajaca skale
     * \param scale skala
     */
    virtual void setScaleFactor(sf::Vector2f scale){
        m_scaleFactors=scale;
    }
    /**
     * Metoda pobierajaca skale
     */
    virtual sf::Vector2f getScaleFactor(){
        return m_scaleFactors;
    }
    /**
     * Metoda pobierajaca pozycje
     */
    virtual sf::Vector2f getPos()=0;
    /**
     * Metoda pobierajaca rozmiar
     */
    virtual sf::Vector2f getSize()=0;
    /**
     * Metoda pobierajaca kolor
     */
    virtual sf::Color getColor()=0;
    /**
     * Metoda ustawiajaca pozycje
     * \param start_pos pozycja startowa
     * \param end_pos pozycja koncowa
     */
    virtual void setPosition(sf::Vector2f start_pos, sf::Vector2f end_pos){

    }
    /**
     * Metoda pobierajaca pozycje startowa
     */
    virtual sf::Vector2f getPosStartPoint(){
        return m_pos;
    }
    /**
     * Metoda pobierajaca pozycje koncowa
     */
    virtual sf::Vector2f getPosEndPoint(){
        return m_size;
    }
    /**
     * Metoda pobierajaca skale
     */
    virtual float getScale(){
        return m_scale;
    }
    /**
     * Metoda pobierajaca typ
     */
    virtual int getType(){
        return m_type;
    }
    /**
     * Metoda ustawiajaca promien
     * \param radius promien
     */
    virtual void setRadiusX(int radius){
    }
    /**
     * Metoda ustawiajaca promien
     * \param radius promien
     */
    virtual void setRadiusY(int radius){

    }
    /**
     * Metoda pobierajaca promien
     */
    virtual int getRadiusX(){
        return 0;
    }
    /**
     * Metoda pobierajaca promien
     */
    virtual int getRadiusY()
    {
        return 0;
    }
    /**
     * Metoda pobierajaca grubosc
     */
    virtual int getThickness(){
        return 0;
    }

    /**
     * Metoda ustawiajaca grubosc
     * \param thickness promien
     */
    virtual void setThickness(int thickness){

    }
    /**
     * Metoda ustawiajaca skale
     * \param scale skala
     */
    virtual void scale(float scale){

    }
    /**
     * Metoda ustawiajaca przesuwajaca
     * \param move wektor przesuniecia
     */
    virtual void translate(sf::Vector2f move){

    }
    /**
     * Metoda rotujaca
     * \param angle o jaki kat obrot
     */
    virtual void rotate(float angle){

    }
    /**
     * Metoda ustawiajaca teksture
     * \param texturePtr wskaznik na texture
     */
    virtual void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        m_pTexture = texturePtr;
    }
    /**
     * Metoda ustawia stan ruchu
     * \param state stan ruchu
     */
    virtual void setMoveState(int state){

    }
    /**
     * Metoda pobierajaca boxcollider
     */
    virtual BoxCollider& getBoxCollider(){
        return m_colisionBox;
    }
    /**
     * Metoda ustawia stan animacji
     * \param state stan animacji
     */
    virtual void setAnimationState(int state){
        m_animationstate = state;
    }
    /**
     * Metoda pobierajaca stan animacji
     */
    virtual int getAnimationState(){
        return m_animationstate;
    }
    /**
     * Metoda ustawiajaca zycie
     * \param health zycie
     */
    virtual void setHealth(float health){

    }
    /**
     * Metoda pobierajaca zycie
     */
    virtual float getHealth(){
        return 0;
    }
    /**
     * Metoda ustawiajaca wartosc ataku
     * \param attack wartosc ataku
     */
    virtual void setAttack(float attack)
    {
    }
    /**
     * Metoda pobierajaca wartosc ataku
     */
    virtual float getAttack()
    {
        return 0;
    }
    /**
     * Metoda ustawiajaca wartosc doswiadczenia
     * \param experience wartosc doswiadczenia
     */
    virtual void setExperience(float experience){
        
    }
    /**
     * Metoda pobierajca doswiadczenie
     */
    virtual float getExperience(){
        return 0;
    }

    protected:
    /**
     * Obiekt kolizji
     */
    BoxCollider m_colisionBox;
    /**
     * Obiekt transform
     */
    Transforms m_transform;
    /**
     * Typ
     */
    int m_type;
    /**
     * Pozycja
     */
    sf::Vector2f m_pos;
    /**
     * Rozmiar
     */
    sf::Vector2f m_size;
    /**
     * Obiekt kolor
     */
    sf::Color m_color;
    /**
     * Skala
     */
    float m_scale;
    /**
     * Czynik skali
     */
    sf::Vector2f m_scaleFactors;
    /**
    * Wskaznik na teksture 
    */
    std::shared_ptr<sf::Texture> m_pTexture;
    /**
     * Wskaznik na aktualnego sprite
     */
    sf::Sprite *m_curSprite;
    /**
     * Stan ruchu
     */
    int m_movestate;
    /**
     * Stan animacji
     */
    int m_animationstate;
};