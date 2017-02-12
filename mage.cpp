#include "mage.h"
#include <iostream>
#include <string>
#include "termcolor.hpp"
#include "game.h"

using namespace termcolor;

Mage::Mage():
    Magic("Mage", 80, 5)
{
    cout << cyan << "Mage " << reset << "added to LightForces" << endl;
}

Unit* Mage::clone()
{
    Mage *tempo = new Mage();
    return tempo;
}

void Mage::backUpUnit(Game &mt, int k)
{
    for(int f = 0; f < k; f++)
    {
        mt.gearUpLightForces(this->clone());
    }
}

void Mage::createLightForces(Game &x, int p)
{
    for(int loop = 0; loop < (p - 1); loop++)
    {
        x.gearUpLightForces(this->clone());
    }
}

