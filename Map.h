#ifndef MAP_H
#define MAP_H
#include <string>

using namespace std;

/*!
 * \brief The Map class models a map that will be used by the Game
 */
class Map
{
private:
    char** MapContents;
    char* FileLocation;
    void SetMap();
    int mapSizeX;
    int mapSizeY;
public:
    ~Map();
    Map(char*, int x, int y);
    void printMap();
    /**
     * @TODO Complete the move to allow an update to the map
     */
    bool Move(int,int,int,int);
    void updateMap(string curr);
    void setMap();
    void insertForces(int numLight, int numDark);
};
#endif
