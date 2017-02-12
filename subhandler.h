#ifndef SUBHANDLER_H
#define SUBHANDLER_H
#include "handler.h"

/*!
 * \brief The subHandler class is derived from the abstract Handler class.
 */
class subHandler: public Handler
{
    public:
        subHandler();
        int handleDamage(vector <Unit*>::iterator pred, vector <Unit*>::iterator prey, int v, Game* m, string state);
};

#endif // SUBHANDLER_H
