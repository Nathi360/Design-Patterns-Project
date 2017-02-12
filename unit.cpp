#include "unit.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"

using namespace std;

Unit::Unit(string v, int h, int d)
{
    unitType = v;
    health = h;
    damage = d;
}

Unit::~Unit()
{
    //Make sure!!
}

int Unit::getHealth()
{
    return health;
}

int Unit::getDamage()
{
    return damage;
}

void Unit::setHealth(int m)
{
    health = m;
}

/*void Unit::setDamage(int o)
{
    damage = o;
}*/

