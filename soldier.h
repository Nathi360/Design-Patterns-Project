#ifndef SOLDIER_H
#define SOLDIER_H
#include "bludgeoning.h"
#include <string>

using namespace std;

/*!
 * \brief The Soldier class is derived from the Bludgeoning class
 */
class Soldier: public Bludgeoning
{
    public:
    /*!
     * \brief Soldier constructor calls the Bludgeoning classes constructor with the relevant parameters
     *        to be used to initialize the Soldier object upon construction
     */
        Soldier();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game&, int);
};

#endif // SOLDIER_H
