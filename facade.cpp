#include "facade.h"
#include "game.h"
#include "unit.h"
#include <vector>
#include "termcolor.hpp"

using namespace termcolor;
using namespace std;

Facade::Facade(int r)
{
    match.darkForceFormation(r);
}

void Facade::backUp()
{
    char bU;

    cout << "\nDo you need backup? Y/N: ";
    cin >> bU;

    if(bU == 'Y' || bU == 'y'){
    do
    {
        char bUType;
        int bUpUnits;

        cout << "\nBackup type: " << endl;
        cout << "\tM - Mage: " << endl;
        cout << "\tS - Soldier: " << endl;
        cout << "\tT - Thief: " << endl;
        cout << "\t\tEnter Back-up type: ";
        cin >> bUType;

        switch(bUType)
        {
            case 'M':
            case 'm':
            {
                cout << "\t\tHow many Mages to summon: ";
                cin >> bUpUnits;
                cout << endl;
                m = new Mage();
                match.gearUpLightForces(m);
                m->createLightForces(match, bUpUnits);
                break;
            }

            case 'S':
            case 's':
            {
                cout << "\t\tHow many Soldiers to summon: ";
                cin >> bUpUnits;
                cout << endl;
                s = new Soldier();
                match.gearUpLightForces(s);
                s->createLightForces(match, bUpUnits);
                break;
            }

            case 'T':
            case 't':
            {
                cout << "\t\tHow many Thieves to summon: ";
                cin >> bUpUnits;
                cout << endl;
                t = new Thief();
                match.gearUpLightForces(t);
                t->createLightForces(match, bUpUnits);
                break;
            }
        }

        cout << "\nDo you need more backup? Y/N: ";
        cin >> bU;

        if(bU == 'n' || bU == 'N')
        {
            cout << endl;
            match.gameStatus();
        }

    }while(bU == 'Y' || bU == 'y');}

    else
    {
        //Fight...?
    }
}

void Facade::playGame()
{
    do
    {
        cout << endl;
        match.gameStatus();
        backUp();
        match.notify();
        match.aim();

    }while(!match.gameOver());
}

void Facade::gameSetUp()
{
    int mNum, sNum, tNum;
    cout << cyan << "\n-------------" << endl;
    cout << "Light Forces:\n";
    cout << "-------------\n" << reset << endl;
    cout << "Number of Mages: ";
    cin >> mNum;
    cout << "Number of Soldiers: ";
    cin >> sNum;
    cout << "Number of Thieves: ";
    cin >> tNum;

    cout << endl;

    if(mNum > 0 )
    {
        m = new Mage();
        match.gearUpLightForces(m);
        m->createLightForces(match, mNum);
    }

    if(sNum > 0)
    {
        s = new Soldier();
        match.gearUpLightForces(s);
        s->createLightForces(match, sNum);
    }

    if(tNum > 0)
    {
        t = new Thief();
        match.gearUpLightForces(t);
        t->createLightForces(match, tNum);
    }

    playGame();
}

int Facade::startUp()
{
     int level;

    cout << green <<  "\n****************************" << endl;
    cout << "****************************" << endl;
    cout << "*** Battle Of The Forces ***" << endl;
    cout << "****************************" << endl;
    cout << "****************************\n" << reset << endl;
    cout << "------------" << endl;
    cout << "Game Set-Up:" << endl;
    cout << "\nEnter Difficulty-level: " << endl;
    cout << "\n1: John-Snow" << endl;
    cout << "2: Casual" << endl;
    cout << "3: Hard" << endl;
    cout << "4: Pro" << endl;
    cout << "5: Quit\t\t\t\t\t\t\t\t";
    cout << green << "Select: " << reset;
    cin >> level;

    if(level == 5)
    {
        cout << "\nExiting: Good-Bye" << endl;
        exit(0);
    }

    do
    {
        if(level <= 0 || level > 5)
        {
            cout << "\nError: Invalid level ~ Enter 1 to 4.";
        }

    }while(level <= 0 || level > 5);

    cout << yellow << "\n------------" << endl;
    cout << "Dark Forces:\n";
    cout << "------------\n" << reset << endl;

    return level;
}
