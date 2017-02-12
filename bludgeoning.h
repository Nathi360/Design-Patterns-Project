#ifndef BLUDGEONING_H
#define BLUDGEONING_H
#include "unit.h"
#include <string>

using namespace std;

/*!
 * \brief The Bludgeoning class is derived from the abstract Unit class
 */
class Bludgeoning: public Unit
{
    public:
        /*!
         * \brief Bludgeoning constructor that calls its parent(Unit) classes constructor
         *        which in turn sets the values for unitType, health and damage.
         */
        Bludgeoning(string, int, int);
        virtual Unit* clone() = 0;
        virtual void backUpUnit(Game&, int) = 0;
        virtual void createLightForces(Game&, int) = 0;
};

#endif // BLUDGEONING_H
