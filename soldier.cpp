#include "soldier.h"
#include <iostream>
#include <string>
#include "termcolor.hpp"
#include "game.h"

using namespace termcolor;

Soldier::Soldier():
    Bludgeoning("Soldier", 100, 8)
{
    cout << cyan << "Soldier " << reset << "added to LightForces" << endl;
}

Unit* Soldier::clone()
{
    Soldier *tempo = new Soldier();
    return tempo;
}

void Soldier::backUpUnit(Game &p, int m)
{
    for(int f = 0; f < m; f++)
    {
        p.gearUpLightForces(this->clone());
    }
}

void Soldier::createLightForces(Game &i, int u)
{
    for(int loop = 0; loop < (u - 1); loop++)
    {
        i.gearUpLightForces(this->clone());
    }
}
