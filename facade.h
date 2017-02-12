#ifndef FACADE_H
#define FACADE_H
#include "game.h"
#include "unit.h"
#include "Map.h"
#include <vector>
#include <string>
#include "rumble.h"

using namespace std;
/*!
 * \brief The Facade class is used to implement the 'Facade'
 *        Design Pattern. This class will be used to simplify the interface
 *        used by the client/user
 */
class Facade
{
    public:
        /*!
         * \brief Facade constructor is sets up the "DarkForces" for the given Game.
         *        Depending on the integer value passed in, the ratio of Monster
         *        Units as well as the number of "DarkForces" will be set accordingly.
         */
        Facade(int);
        /*!
         * \brief This function is used to let the player/user set the configuration
         *        of the "LightForces" by requesting the user to indicate the number
         *        of each type Unit to be added.
         */
        void gameSetUp();
        /*!
         * \brief This function loads the game and promts the user to select a difficulty
         *        level.
         * \return The returned value is passed to the Facade constructor and thus is used
         *         to configure the ratios/ quantity of "DarkForces" int the Game.
         */
        int startUp();
        void backUp();
        /*!
         * \brief This function simulates the game.
         */
        void playGame();

    private:
        Mage *m;
        Soldier *s;
        Thief *t;
        Rumble match;
};

#endif // FACADE_H
