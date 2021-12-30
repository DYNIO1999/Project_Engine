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

class EnemyBattle: public Object
{
private:

public:
    EnemyBattle(std::shared_ptr<sf::Texture> texturePtr, sf::Vector2f pos, sf::Vector2f size, Engine *enginePtr)
    {
        m_enginePtr = enginePtr;
        m_pos = pos;
        m_size = size;
        m_movestate = NO_INPUT;
        m_pTexture = texturePtr;
        m_enemySprite.setTexture(*m_pTexture);
        m_enemySprite.setPosition(m_pos - sf::Vector2f(5, 5));

        // DEBUG
        m_enemyShape.setFillColor(sf::Color::Transparent);
        m_enemyShape.setOutlineColor(sf::Color::Red);
        m_enemyShape.setOutlineThickness(1.0f);

        BoxCollider temp(m_pos.x, m_pos.y, m_size.x, m_size.y);
        m_colisionBox = temp;

        m_animationstate = ENEMY_ANIMATION_IDLE;
        m_enemyAnimation = new Animation();
        m_enemyHealthBar.init(m_pos.x, m_pos.y, 200, 50);
        m_enemyHealth = 100;
    }

    ~EnemyBattle()
    {
        delete m_enemyAnimation;
    }

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

    void draw(sf::RenderWindow &win_ref)
    {
        win_ref.draw(m_enemySprite);
        win_ref.draw(m_enemyShape);
        m_enemyHealthBar.draw(win_ref);
    }

    void setSize(sf::Vector2f size)
    {
        m_size = size;
    }

    void setPosition(sf::Vector2f pos)
    {
        m_pos = pos;
    }

    void setScale(float scale)
    {
        m_scale = scale;
    }

    sf::Vector2f getPos()
    {
        return m_pos;
    }

    sf::Vector2f getSize()
    {
        return m_size;
    }

    void setColor(sf::Color color)
    {
        m_color = color;
    }

    sf::Color getColor()
    {
        return m_color;
    }

    float getScale()
    {
        return m_scale;
    }

    void setTexture(std::shared_ptr<sf::Texture> texturePtr)
    {
        
        m_pTexture = texturePtr;
        m_enemySprite.setTexture(*m_pTexture);
    }

    BoxCollider &getBoxCollider()
    {
        return m_colisionBox;
    }

    void setScaleFactor(sf::Vector2f scale)
    {
        m_scaleFactors = scale;
    }

    sf::Vector2f getScaleFactor()
    {
        return m_scaleFactors;
    }

    void setHealth(float health)
    {
        m_enemyHealth = health;
    }

    float getHealth()
    {
        return m_enemyHealth;
    }

    void setAttack(float attack)
    {
        m_enemyAttack = attack;
    }

    float getAttack()
    {
        return m_enemyAttack;
    }

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

    Animation *m_enemyAnimation;
    sf::RectangleShape m_enemyShape;
    float m_enemyHealth;
    float m_enemyAttack;
    HealthBar m_enemyHealthBar;
    sf::Sprite m_enemySprite;
    Engine *m_enginePtr;
};

