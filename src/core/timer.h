#pragma once
#include <SFML/Graphics.hpp>
struct Timer
{
    sf::Clock m_Clock;
    float runTime;
    bool isPaused;

    Timer()
    {
        isPaused = false;
        runTime = 0;
        m_Clock.restart();
    }

    void Reset()
    {
        m_Clock.restart();
        runTime = 0;
        isPaused = false;
    }

    void Start()
    {
        if (isPaused)
        {
            m_Clock.restart();
        }
        isPaused = false;
    }

    void Pause()
    {
        if (!isPaused)
        {
            runTime += m_Clock.getElapsedTime().asSeconds();
        }
        isPaused = true;
    }

    float GetElapsedSeconds()
    {
        if (!isPaused)
        {
            return runTime + m_Clock.getElapsedTime().asSeconds();
        }
        return runTime;
    }
};
