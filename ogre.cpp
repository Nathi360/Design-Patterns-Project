#include "ogre.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

Ogre::Ogre():
    Bludgeoning("Bludgeoning", 120, 5)
{
    cout << yellow << "Ogre " << reset << "added to DarkForces" << endl;
}

Unit* Ogre::clone()
{
    Ogre *tempo = new Ogre();
    return tempo;
}

void Ogre::backUpUnit(Game &, int)
{

}

void Ogre::createLightForces(Game&, int)
{

}
