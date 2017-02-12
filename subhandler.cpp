#include "subhandler.h"
#include "unit.h"

using namespace std;

subHandler::subHandler()
{

}

int subHandler::handleDamage(vector <Unit*>::iterator pred, vector <Unit*>::iterator prey, int v, Game* m, string state)
{
    m->cleanUp(pred, prey);

    if(state == "User")
    {
        for(prey = darkForces.begin(); prey < darkForces.end() && v > 0; prey++)
        {
            m->cleanUp(pred, prey);

            if((*prey)->getHealth() >= v)
            {
                (*prey)->setHealth((*prey)->getHealth() - v);
                v = 0;
            }
            else if((*prey)->getHealth() < v)
            {
                (*prey)->setHealth(0);
                v -= (*prey)->getHealth();
            }
        }
    }

    else if(state == "Computer")
    {
        for(prey = lightForces.begin(); prey < lightForces.end() && v > 0; prey++)
        {
            m->cleanUp(pred, prey);

            if((*prey)->getHealth() >= v)
            {
                (*prey)->setHealth((*prey)->getHealth() - v);
                v = 0;
            }
            else if((*prey)->getHealth() < v)
            {
                (*prey)->setHealth(0);
                v -= (*prey)->getHealth();
            }
        }
    }
}
