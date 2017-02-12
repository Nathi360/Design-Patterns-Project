#ifndef ELEMENTAL_H
#define ELEMENTAL_H
#include "magic.h"
#include <string>

using namespace std;

/*!
 * \brief The Elemental class is derived from the Magic class
 */
class Elemental: public Magic
{
    public:
    /*!
     * \brief Elemental constructor calls the Magic classes constructor with the relevant parameters
     *        to be used to initialize the Elemental object upon construction
     */
        Elemental();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game&, int);
};

#endif // ELEMENTAL_H
