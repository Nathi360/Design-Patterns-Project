#ifndef MAGE_H
#define MAGE_H
#include "magic.h"
#include <string>

using namespace std;

/*!
 * \brief The Mage class is derived from the Magic class
 */
class Mage: public Magic
{
    public:
        /*!
         * \brief Mage constructor calls the Magic classes constructor with the relevant parameters
         *        to be used to initialize the Mage object upon construction
         */
        Mage();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game &, int);
};

#endif // MAGE_H
