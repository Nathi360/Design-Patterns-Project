#ifndef RUMBLE_H
#define RUMBLE_H
#include "game.h"
#include "subhandler.h"
#include "Map.h"
#include <string>

using namespace std;

/*!
 * \brief The Rumble class is derived from the Game class and implements its methods
 */
class Rumble: public Game
{
    public:
        Rumble();
        Rumble(string);
        virtual void attack(vector<Unit*>::iterator, vector<Unit*>::iterator, int);
        void aim();
        void notify();
        /*!
         * \brief setState sets the state of the Game as to who is attacking now
         * \param v state
         */
        void setState(string v);
        /*!
         * \brief getState
         * \return Returns the current state of the Game
         */
        string getState();

    private:
        string currState;
        subHandler* glove;
};

#endif // RUMBLE_H
