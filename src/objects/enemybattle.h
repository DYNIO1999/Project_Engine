#pragma once
#include "object.h"
#include "../core/core.h"
#include "../animation/animation.h"
#include "../gui/healthbar.h"
enum ENEMY_ANIMATION_STATES
{
    ENEMY_ANIMATION_IDLE,
    ENEMY_ANIMATION_ATTACK,
    ENEMY_ANIMATION_DEATH,
    ENEMY_ANIMATION_HIT,
};
/**
 * Konstruktor klasy enemy
 */
class EnemyBattle: public Object
{
private:

public:
    /**
     * Konstruktor klasy enemy
     * \param texturePtr wskaznik na obiekt tekstury
     * \param pos pozycja
     * \param size rozmiar
     * \param enginePtr wskaznik na silnik gry
     */
    EnemyBattle(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size, Engine *enginePtr)
    {
        m_enginePtr = enginePtr;
        m_pos = pos;
        m_size = size;
        m_movestate = NO_INPUT;
        m_pTexture = texturePtr;
        m_enemySprite.setTexture(*m_pTexture);
        m_enemySprite.setPosition(m_pos - sf::Vector2f(5, 5));

        /*// DEBUG
        m_enemyShape.setFillColor(sf::Color::Transparent);
        m_enemyShape.setOutlineColor(sf::Color::Red);
        m_enemyShape.setOutlineThickness(1.0f);*/

        BoxCollider temp(m_pos.x, m_pos.y, m_size.x, m_size.y);
        m_colisionBox = temp;

        m_animationstate = ENEMY_ANIMATION_IDLE;
        m_enemyAnimation = new Animation();
        m_enemyHealthBar.init(m_pos.x, m_pos.y, 200, 50);
        m_enemyHealth = 100;
    }
    /**
     * Destruktor klasy enemy
     */
    ~EnemyBattle()
    {
        delete m_enemyAnimation;
    }
    /**
     * Metoda aktualizujaca przeciwnika
     * \param dt deltatime
     */
    int processEvents(TimeStep dt)
    {
        m_enemyAnimation->Update(0, dt);
        m_enemySprite.setTextureRect(m_enemyAnimation->m_textureRect);

        m_enemySprite.setPosition(m_pos - sf::Vector2f(50 * m_scale, 0));
        m_enemySprite.setScale(m_scale, m_scale);

        BoxCollider temp(m_pos.x, m_pos.y, m_size.x * (m_scale), m_size.y * (m_scale));
        m_colisionBox = temp;
        m_colisionBox.setPos(m_pos);

        m_enemyShape.setPosition(m_pos);
        m_enemyShape.setSize(sf::Vector2f(m_size.x * (m_scale), m_size.y * (m_scale)));

        float test = m_size.x - 100;
        test = test / 2;

        m_enemyHealthBar.update(m_enemyHealth * 2, m_pos.x - test, m_pos.y - 50);

        return 0;
    }
    /**
     * Metoda rysujaca przeciwnika
     * \param win_ref referencja do renderu
     */
    void draw(sf::RenderWindow &win_ref)
    {
        win_ref.draw(m_enemySprite);
        //win_ref.draw(m_enemyShape);
        m_enemyHealthBar.draw(win_ref);
    }
    /**
     * Metoda ustawiajaca rozmiar przeciwnika
     * \param size rozmiar
     */
    void setSize(sf::Vector2f size)
    {
        m_size = size;
    }
    /**
     * Metoda ustawiajaca pozycje przeciwnika
     * \param pos pozycja
     */
    void setPosition(sf::Vector2f pos)
    {
        m_pos = pos;
    }
    /**
     * Metoda ustawiajaca skale przeciwnika
     * \param scale skala
     */
    void setScale(float scale)
    {
        m_scale = scale;
    }
    /**
     * Metoda podajaca pozycje przeciwnika
     */
    sf::Vector2f getPos()
    {
        return m_pos;
    }
    /**
     * Metoda podjaca rozmiar przeciwnika
     */
    sf::Vector2f getSize()
    {
        return m_size;
    }
    /**
     * Metoda ustawiajaca kolor
     * \param color oniekt kolorow
     */
    void setColor(sf::Color color)
    {
        m_color = color;
    }
    /**
     * Metoda podjaca kolor
     */
    sf::Color getColor()
    {
        return m_color;
    }
    /**
     * Meotda podajaca skale
     */
    float getScale()
    {
        return m_scale;
    }
    /**
     * Metoda ustawia teksture
     * \param texturePtr wskaznik na teksture
     */
    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        
        m_pTexture = texturePtr;
        m_enemySprite.setTexture(*m_pTexture);
    }
    /**
     * Metoda podaje collideboxa
     */
    BoxCollider &getBoxCollider()
    {
        return m_colisionBox;
    }
    /**
     * Metoda ustawia skale
     * \param scale skala
     */
    void setScaleFactor(sf::Vector2f scale)
    {
        m_scaleFactors = scale;
    }
    /**
     * Metoda podjaca skale
     */
    sf::Vector2f getScaleFactor()
    {
        return m_scaleFactors;
    }
    /**
     * Metoda ustawia zycie
     * \param health zycie
     */
    void setHealth(float health)
    {
        m_enemyHealth = health;
    }
    /**
     * Metoda podaje zycie
     */
    float getHealth()
    {
        return m_enemyHealth;
    }
    /**
     * Metoda ustawia atak
     * \param attack wartosc ataku
     */
    void setAttack(float attack)
    {
        m_enemyAttack = attack;
    }
    /**
     * Metoda podaje atak
     */
    float getAttack()
    {
        return m_enemyAttack;
    }
    /**
     * Metoda ustawia aktualny typ animacji
     * \param state stan animacji
     */
    void setAnimationState(int state)
    {
        m_animationstate = state;
        if (m_animationstate == ENEMY_ANIMATION_ATTACK)
        {
            m_enemyAnimation->initAnimation(m_pTexture, sf::Vector2u(8, 1), 0.1f);
        }
        else if (m_animationstate == ENEMY_ANIMATION_DEATH)
        {
            m_enemyAnimation->initAnimation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }
        else if (m_animationstate == ENEMY_ANIMATION_IDLE)
        {
            m_enemyAnimation->initAnimation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }
        else
        {
            m_enemyAnimation->initAnimation(m_pTexture, sf::Vector2u(4, 1), 0.1f);
        }
    }

public:
    /**
     * Wskaznik na obiekt animacji
     */
    Animation *m_enemyAnimation;
    /**
     * Obiekt przetrzymuje rectangleshape
     */
    sf::RectangleShape m_enemyShape;
    /**
     * Zmienna przetrzymuje zycie
     */
    float m_enemyHealth;
    /**
     * Zmienna przetrzymuje wartosc ataku
     */
    float m_enemyAttack;
    /**
     * Obiekt przetrzymuje pasek  zycia
     */
    HealthBar m_enemyHealthBar;
    /**
     * Obiekt przetrzymuje sprite
     */
    sf::Sprite m_enemySprite;
    /**
     * Wskaznik na silnik gry
     */
    Engine *m_enginePtr;
};

