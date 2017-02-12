#ifndef OGRE_H
#define OGRE_H
#include "bludgeoning.h"
#include <string>

using namespace std;

/*!
 * \brief The Ogre class is derived from the Bludgeoning class
 */
class Ogre: public Bludgeoning
{
    public:
    /*!
     * \brief Ogre constructor calls the Bludgeoning classes constructor with the relevant parameters
     *        to be used to initialize the Ogre object upon construction
     */
        Ogre();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game &, int);
};

#endif // OGRE_H
