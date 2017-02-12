#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include "termcolor.hpp"
#include <vector>
#include <string>

int count = 1;
bool attack = false;

using namespace termcolor;
using namespace std;

Map::Map(char* fileName, int x, int y)
{
    FileLocation = fileName;
    mapSizeX = x;
    mapSizeY = y;
    setMap();
}

Map::~Map()
{
   for(int l = 0; l < mapSizeX; l++)
   {
   		delete [] MapContents[l];
   }
   	delete MapContents;
}

void Map::setMap()
{
    MapContents = new char*[mapSizeX];
    for(int i=0;i<mapSizeX;i++)
    {
        MapContents[i] = new char[mapSizeY];
    }
    ifstream myReadFile;
    myReadFile.open(FileLocation);
    string output;
    int count = 0;
    if (myReadFile.is_open()) 
    {
        while (getline(myReadFile, output)) 
        {
            strcpy(MapContents[count], output.c_str());
            count++;
        }
    }
    myReadFile.close();
}

void Map::insertForces(int numLight, int numDark)
{
    unsigned core = time(0);
    srand(core);
    int row = 0, coll = 0;

    if(attack == true)
    {
    if(count%2 == 0)
    {
        numDark -= 1;
    }
    else if(count%2 != 0)
    {
        numLight -= 1;
    }
    }

    for(int l = 0; l < numLight; l++)
    {
        do
        {
            row = rand()%20;
            coll = rand()%21;

        }while(MapContents[row][coll] != ' ');

        MapContents[row][coll] = 'L';
    }

    for(int l = 0; l < numDark; l++)
    {
        do
        {
            row = rand()%20;
            coll = rand()%21;

        }while(MapContents[row][coll] != ' ');

        MapContents[row][coll] = 'D';
    }

    count++;
    attack = true;
}

void Map::printMap()
{
    for(int i = 0; i < mapSizeX; i++)
    {
        for(int j = 0; j < mapSizeY; j++)
        {
            if((MapContents[i])[j] == 'L')
            {
                cout << cyan << (MapContents[i])[j] << reset;
            }
            else if((MapContents[i])[j] == 'D')
            {
                cout << yellow << (MapContents[i])[j] << reset;
            }
            else
            {
                cout << (MapContents[i])[j];
            }
        }
        cout << endl;
    }
}

bool Map::Move(int currX,int currY,int moveX,int moveY)
{
    //Wont be using..
}

void Map::updateMap(string curr)
{
    bool status = false;
    if(curr == "User")
    {
        for(int i = 0; i < mapSizeX; i++)
        {
            for(int j = 0; j < mapSizeY; j++)
            {
                if((MapContents[i])[j] == 'L')
                {
                    cout << cyan << (MapContents[i])[j] << reset;
                }
                else if((MapContents[i])[j] == 'D')
                {
                    status = true;
                    (MapContents[i])[j] == ' ';
                    cout << yellow << (MapContents[i])[j] << reset;
                }
                else
                {
                    cout << (MapContents[i])[j];
                }
            }
            cout << endl;
        }
        if(status == false)
        {
            cout << "The LightForces have won" << endl;
            exit(0);
        }
    }

    else if(curr == "Computer")
    {
        for(int i = 0; i < mapSizeX; i++)
        {
            for(int j = 0; j < mapSizeY; j++)
            {
                if((MapContents[i])[j] == 'L')
                {
                    status = true;
                    (MapContents[i])[j] == ' ';
                    cout << cyan << (MapContents[i])[j] << reset;
                }
                else if((MapContents[i])[j] == 'D')
                {
                    cout << yellow << (MapContents[i])[j] << reset;
                }
                else
                {
                    cout << (MapContents[i])[j];
                }
            }
            cout << endl;
        }
    }
    if(status == false)
    {
        cout << "The DarkForces have won" << endl;
        exit(0);
    }
}


