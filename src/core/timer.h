#pragma once
#include <SFML/Graphics.hpp>

/**
 * Klasa Timer
 */
struct Timer
{
    
    sf::Clock m_Clock;
    float runTime;
    bool isPaused;
    /**
     * Konstruktor klasy timer
     */
    Timer()
    {
        isPaused = false;
        runTime = 0;
        m_Clock.restart();
    }
    /**
     * Metoda resetujaca timer
     */
    void Reset()
    {
        m_Clock.restart();
        runTime = 0;
        isPaused = false;
    }
    /**
     * Metoda uruchamiajaca timer
     */
    void Start()
    {
        if (isPaused)
        {
            m_Clock.restart();
        }
        isPaused = false;
    }
    /**
     * Metoda pauzujaca timer
     */
    void Pause()
    {
        if (!isPaused)
        {
            runTime += m_Clock.getElapsedTime().asSeconds();
        }
        isPaused = true;
    }
    /**
     * Metoda podaje czas z timer
     */
    float GetElapsedSeconds()
    {
        if (!isPaused)
        {
            return runTime + m_Clock.getElapsedTime().asSeconds();
        }
        return runTime;
    }
};
