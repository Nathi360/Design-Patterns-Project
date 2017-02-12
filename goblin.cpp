#include "goblin.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

Goblin::Goblin():
    Piercing("Goblin", 50, 12)
{
    cout << yellow << "Goblin " << reset << "added to DarkForces" << endl;
}

Unit* Goblin::clone()
{
    Goblin *tempo = new Goblin();
    return tempo;
}

void Goblin::backUpUnit(Game&, int)
{

}

void Goblin::createLightForces(Game&, int)
{

}
