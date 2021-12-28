#pragma once
#include <iostream>
#include <cstdlib>

struct DiceRoller
{
    int roll;
    int min;
    int max;

    DiceRoller(){
        srand(time(nullptr));

    };
    ~DiceRoller(){};

    int diceRoll_1K10(){
        min =1;
        max =10;
        roll = rand() % (max-min+1)+min;
        return roll;
    }
    int diceRoll_1K1()
    {
        min = 0;
        max = 1;
        roll = rand() % (max - min + 1) + min;
        return roll;
    }
    int diceRoll_1K3()
    {
        min = 1;
        max = 3;
        roll = rand() % (max - min + 1) + min;
        return roll;
    }
};

