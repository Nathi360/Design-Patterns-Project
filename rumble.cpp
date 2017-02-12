#include "rumble.h"
#include "unit.h"
#include <iostream>
#include <ctime>

using namespace std;

vector <Unit*>::iterator light;
vector <Unit*>::iterator dark;

Rumble::Rumble()
{
    currState = "Computer";
}

Rumble::Rumble(string m)
{
    currState = m;
    glove = 0;
}

void Rumble::attack(vector<Unit*>::iterator pred, vector<Unit*>::iterator prey, int target)
{
    if(currState == "Computer")
    {
        lightForces.pop_back();
    }
    else if(currState == "User")
    {
        darkForces.pop_back();
    }

    cleanUp(pred, prey);
}

void Rumble::aim()
{
    vector <Unit*>::iterator light = lightForces.begin();
    vector <Unit*>::iterator dark = darkForces.begin();

    char action;

    if(currState == "User")
    {
        cout << "\nYour move: Enter [X] to attack or [S] to stand-down: ";
        cin >> action;

        int index;

        if(action == 'X' || action == 'x')
        {
            cout << "Attacking: Enter index of unit to attack: ";
            cin >> index;
            attack(light, dark, index);
        }
        else if(action == 'S' || action == 's')
        {
            cout << "Standing-down" << endl;
        }
    }
    else if(currState == "Computer")
    {
        cout << "\nComputer's move: Please wait: " << endl;

        unsigned v = time(0);
        srand(v);
        int here = rand()%(lightForces.size() + 1);
        cleanUp(light, dark);
        attack(dark, light, here);
    }
}

void Rumble::notify()
{
    if(currState == "User")
    {
        setState("Computer");
    }
    else if(currState == "Computer")
    {
        setState("User");
    }
}

void Rumble::setState(string p)
{
    currState = p;
}

string Rumble::getState()
{
    return currState;
}
