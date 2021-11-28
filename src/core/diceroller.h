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
};
