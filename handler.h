#ifndef HANDLER_H
#define HANDLER_H
#include "game.h"

/*!
 * \brief The Handler class is used to implement the Chain of Responsibility Design Pattern
 */
class Handler: public Game
{
    public:
        Handler();
        /*!
         * \brief This function is ussed to delegate damage that could no be taken due to a
         *        Unit dying before all damage could be dealt.
         * \param predator is the Unit attacking.
         * \param prey is the Unit under attack.
         * \param m is the remaining amount of damage that needs to be delegated to another
         *        Unit(s)
         * \param l is the current Game we are in/playing
         * \param state is a string variable indicating which party is attacking
         * \return The function returns any damage that could not be delegated.
         */
        virtual int handleDamage(vector <Unit*>::iterator predator, vector <Unit*>::iterator prey, int m, Game* l, string state);

    private:
        Handler* successor;
};

#endif // HANDLER_H
