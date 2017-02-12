#ifndef THIEF_H
#define THIEF_H
#include "piercing.h"
#include <string>

using namespace std;

/*!
 * \brief The Thief class is derived from the Piercing class
 */
class Thief: public Piercing
{
    public:
    /*!
     * \brief Thief constructor calls the Piercing classes constructor
     *        with the relevant parameters to be used to initialize the
     *        Thief object upon construction
     */
        Thief();
        virtual Unit* clone();
        virtual void backUpUnit(Game&, int);
        virtual void createLightForces(Game&, int);
};

#endif // THIEF_H
