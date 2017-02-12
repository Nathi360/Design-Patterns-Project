#include "elemental.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

Elemental::Elemental():
    Magic("Elemental", 85, 4)
{
    cout << yellow << "Elemental " << reset << "added to DarkForces" << endl;
}

Unit* Elemental::clone()
{
    Elemental *tempo = new Elemental();
    return tempo;
}

void Elemental::backUpUnit(Game &, int)
{

}

void Elemental::createLightForces(Game&, int)
{

}
