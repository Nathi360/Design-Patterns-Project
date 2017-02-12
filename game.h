#ifndef GAME_H
#define GAME_H
#include <vector>
#include <cstdlib>
#include "mage.h"
#include "soldier.h"
#include "thief.h"
#include "Map.h"

using namespace std;

class Unit;

/*!
 * \brief The Game class is an abstract class to which all Game's are modelled from.
 */
class Game
{
    public:
        Game();
        ~Game();
        /*!
         * \brief This function is used to check if both parties still have Units to fight
         * \return Returns true if atleast one party has run out of Units, else false.
         */
        bool gameOver();
        /*!
         * \brief This function is used to remove all dead Units from the Game.
         */
        void cleanUp(vector<Unit*>::iterator, vector<Unit*>::iterator);
        /*!
         * \brief This function prints to the screen the status of the Game (Map, Unit locations etc)
         */
        void gameStatus();
        /*!
         * \brief This function adds the specified Unit to the squad of "LightForces"
         */
        void gearUpLightForces(Unit*);
        /*!
         * \brief This function adds "DarkForces" to the Game, depending on the value
         *        of the integer parameter passed to it.
         */
        void darkForceFormation(int);
        /*!
         * \brief This function simulates an attack by one type Force on another
         * \param The two iterators representing the "Light" and "DarkForces"
         *        and the integer value being the index of the targeted Unit.
         */
        virtual void attack(vector<Unit*>::iterator, vector<Unit*>::iterator, int) = 0;
        /*!
         * \brief This function promts the player to choose between attacking and standing-
         *        down. Furthermore, the player has to select their target.
         */
        virtual void aim() = 0;
        /*!
         * \brief This function updates after each attack made by either party.
         *        The party that was last attacked will now have a chance to attack.
         */
        virtual void notify() = 0;
        Map* getMap()
        {
            return field;
        }

    private:
        Map* field;
        char* point;

    protected:
        /*!
         * \brief Vector representing squad/army of "LightForces"
         */
        vector <Unit*> lightForces;
        /*!
         * \brief Vector representing squad/army of "DarkForces"
         */
        vector <Unit*> darkForces;


};

#endif // GAME_H
