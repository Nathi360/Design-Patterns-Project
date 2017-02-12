#include "thief.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"
#include "game.h"

using namespace termcolor;

Thief::Thief():
    Piercing("Thief", 60, 10)
{
    cout << cyan << "Thief " << reset << "added to LightForces" << endl;
}


Unit* Thief::clone()
{
    Thief *tempo = new Thief();
    return tempo;
}

void Thief::backUpUnit(Game &t, int s)
{
    for(int f = 0; f < s; f++)
    {
        t.gearUpLightForces(this->clone());
    }
}

void Thief::createLightForces(Game& w, int h)
{
    for(int loop = 0; loop < (h - 1); loop++)
    {
        w.gearUpLightForces(this->clone());
    }
}
