#include <iostream>
#include "game.h"
#include "unit.h"
#include "mage.h"
#include "elemental.h"
#include "soldier.h"
#include "ogre.h"
#include "thief.h"
#include "goblin.h"
#include <vector>
#include <string>
#include "termcolor.hpp"
#include "facade.h"

using namespace termcolor;

int main()
{
    Facade *alles;
    int value = alles->startUp();
    alles = new Facade(value);
    alles->gameSetUp();

    delete alles;

    return 0;
}

