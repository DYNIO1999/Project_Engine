#pragma once
#include <iostream>
#include <cstdlib>

/**
 * Struktura do rzucania koscia
 */
struct DiceRoller
{
    /**
     * aktualne wyrzucenie
     */
    int roll;
    /**
     * minimalna wartosc wyrzucenia
     */
    int min;
    /**
     * maksymalna wartosc wyrzucenia
     */
    int max;
    /**
     * Konstruktor klasy do rzucania koscia
     */
    DiceRoller(){
        srand(time(nullptr));
    };
    /**
     * Destruktor klasy do rzucania koscia
     */
    ~DiceRoller(){};
    /**
     * Metoda do rzucania koscia
     */
    int diceRoll_1K10(){
        min =1;
        max =10;
        roll = rand() % (max-min+1)+min;
        return roll;
    }
    /**
     * Metoda do rzucania koscia
     */
    int diceRoll_1K1()
    {
        min = 0;
        max = 1;
        roll = rand() % (max - min + 1) + min;
        return roll;
    }
    /**
     * Metoda do rzucania koscia
     */
    int diceRoll_1K3()
    {
        min = 1;
        max = 3;
        roll = rand() % (max - min + 1) + min;
        return roll;
    }
    /**
     * Metoda do rzucania koscia
     */
    int diceRoll(int n)
    {
        min = 0;
        max = n-1;
        roll = rand() % (max - min + 1) + min;
        return roll;
    }
};

