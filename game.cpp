#include "unit.h"
#include "game.h"
#include"elemental.h"
#include "mage.h"
#include "soldier.h"
#include "ogre.h"
#include "thief.h"
#include "goblin.h"
#include <iostream>
#include "termcolor.hpp"
#include <cstdlib>
#include <vector>

bool callStatus = true;

using namespace termcolor;

char name[] = "Map.txt";

Game::Game()
{
    field = 0;
    point = 0;
}

Game::~Game()
{
    cout << "\nDestructing.." << endl;

    for(size_t loop = 0; loop < lightForces.size(); loop++)
    {
        delete lightForces[loop];
    }

    for(size_t loop = 0; loop < darkForces.size(); loop++)
    {
        delete darkForces[loop];
    }

    //delete field;
}

bool Game::gameOver()
{
    vector <Unit*>::iterator light = lightForces.begin();
    vector <Unit*>::iterator dark = darkForces.begin();
    cleanUp(light, dark);

    if(lightForces.empty() || darkForces.empty())
    {
        return true;
    }

    return false;
}

void Game::cleanUp(vector<Unit*>::iterator l, vector<Unit*>::iterator d)
{
    if(lightForces.size() == 0)
    {
        cout << "DarkForces have won!!" << endl;
    }
    else if(darkForces.size() == 0)
    {
        cout << "LightForces have won!!" << endl;
    }
}

void Game::gameStatus()
{
    cout << cyan << "LightForce units: " << reset << lightForces.size() << endl;
    cout << yellow << "DarkForce units: " << reset << darkForces.size() << endl;

    point = name;
    name[7] = '\0';
    field = new Map(point, 20, 21);

    cout << endl;
    field->insertForces(lightForces.size(), darkForces.size());
    cout << "------------------" << endl;
    cout << "A: Proceed to map" << endl;
    cout << "Q: Quit\t\t\t\t\t\t\t\t";
    cout << green << "Select: " << reset;
    char choice;
    cin >> choice;
    cout << endl;

    switch(choice)
    {
        case 'a':
        case 'A':
        {
            field->printMap();
            break;
        }
        case 'q':
        case 'Q':
        {
            cout << "Exiting: Good-Bye" << endl;
            exit(0);
        }
    }
}

void Game::gearUpLightForces(Unit* gear)
{
    lightForces.push_back(gear);
}

void Game::darkForceFormation(int vn)
{
    switch(vn)
    {
        case 1:
        {
            for(int loop = 0; loop < 4; loop++)
            {
                Goblin *gob = new Goblin();
                darkForces.push_back(gob);
            }

            for(int loop = 0; loop < 4; loop++)
            {
                Elemental *wiz = new Elemental();
                darkForces.push_back(wiz);
            }

            for(int loop = 0; loop < 2; loop++)
            {
                Ogre *shrek = new Ogre();
                darkForces.push_back(shrek);
            }
            break;
        }
        case 2:
        {
            for(int loop = 0; loop < 3; loop++)
            {
                Goblin *gob = new Goblin();
                darkForces.push_back(gob);
            }

            for(int loop = 0; loop < 4; loop++)
            {
                Elemental *wiz = new Elemental();
                darkForces.push_back(wiz);
            }

            for(int loop = 0; loop < 6; loop++)
            {
                Ogre *shrek = new Ogre();
                darkForces.push_back(shrek);
            }
            break;
        }

        case 3:
        {
            for(int loop = 0; loop < 5; loop++)
            {
                Goblin *gob = new Goblin();
                darkForces.push_back(gob);
            }

            for(int loop = 0; loop < 3; loop++)
            {
                Elemental *wiz = new Elemental();
                darkForces.push_back(wiz);
            }

            for(int loop = 0; loop < 7; loop++)
            {
                Ogre *shrek = new Ogre();
                darkForces.push_back(shrek);
            }
            break;
        }

        case 4:
        {
            for(int loop = 0; loop < 10; loop++)
            {
                Goblin *gob = new Goblin();
                darkForces.push_back(gob);
            }

            for(int loop = 0; loop < 10; loop++)
            {
                Ogre *shrek = new Ogre();
                darkForces.push_back(shrek);
            }
            break;
        }
    }
}
