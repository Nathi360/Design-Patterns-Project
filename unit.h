#ifndef UNIT_H
#define UNIT_H
#include <string>
//#include "game.h"

class Game;

using namespace std;
/*!
 * \brief An abstract/base class to which all units are modelled from
 */
class Unit
{
    private:
    /*!
         * \brief A units life value, health = 0 meaning the unit has been killed
         */
        int health;
        /*!
         * \brief The amount of damage the specified unit can induce on another
         */
        int damage;
        /*!
         * \brief The units description
         */
        string unitType;

    public:
        /*!
         * \brief Constructor that initializes unitType, health and damage
         */
        Unit(string, int, int);
        /*!
         * \brief Class destructor
         */
        virtual ~Unit();
        /*!
         * \brief An accessor funtion that gets  the health value
         * \return This function returns the health value for the unit
         */
        int getHealth();
        /*!
         * \brief An accessor funtion that gets  the damage value
         * \return This function returns the damage value for the unit
         */
        int getDamage();
        /*!
         * \brief This function sets or resets the health value for the unit
         */
        void setHealth(int);
        /*!
         * \brief This function is used to clone an already existing Unit
         * \return This function returns a pointer to the cloned Unit
         */
        virtual Unit* clone() = 0;
        /*!
         * \brief This function is called when ever the player wants to re-inforce his/her squad
         */
        virtual void backUpUnit(Game&, int) = 0;
        /*!
         * \brief This function prepares the creation (initialization) of the "LightForces"
         * \param m - The instance of the Game class to which the "LightForces" will be added to
         * \param t - The number of "LightForces" to be created/cloned
         */
        virtual void createLightForces(Game& m, int t) = 0;
};

#endif // UNIT_H
