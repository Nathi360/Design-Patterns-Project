#ifndef GOBLIN_H
#define GOBLIN_H
#include "piercing.h"
#include <string>

using namespace std;

/*!
 * \brief The Thief class is derived from the Piercing class
 */
class Goblin: public Piercing
{
    public:
    /*!
     * \brief Goblin constructor calls the Piercing classes constructor
     *        with the relevant parameters to be used to initialize the
     *        Goblin object upon construction
     */
        Goblin();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game &, int);
};

#endif // GOBLIN_H
