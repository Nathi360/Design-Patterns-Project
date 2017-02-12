#ifndef PIERCING_H
#define PIERCING_H
#include "unit.h"
#include <string>

using namespace std;

/*!
 * \brief The Piercing class is derived from the abstract Unit class
 */
class Piercing: public Unit
{
    public:
        /*!
         * \brief Piecing constructor that calls its parent(Unit) classes constructor
         *        which in turn sets the values for unitType, health and damage.
         */
        Piercing(string, int, int);
        virtual Unit* clone() = 0;
        virtual void backUpUnit(Game&, int) = 0;
        virtual void createLightForces(Game&, int) = 0;
};

#endif // PIERCING_H
