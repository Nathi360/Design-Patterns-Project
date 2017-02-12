#ifndef MAGIC_H
#define MAGIC_H
#include "unit.h"
#include <string>

//class Game;

using namespace std;

/*!
 * \brief The Magic class is derived from the abstract Unit class
 */
class Magic: public Unit
{
    public:
        /*!
         * \brief Magic constructor that calls its parent(Unit) classes constructor
         *        which in turn sets the values for unitType, health and damage.
         */
        Magic(string, int, int);
        virtual Unit* clone() = 0;
        virtual void backUpUnit(Game&, int) = 0;
        virtual void createLightForces(Game&, int) = 0;
};

#endif // MAGIC_H
