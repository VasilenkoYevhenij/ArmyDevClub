#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../attacks/VampireAttack.h"
#include "../interfaces/Observable.h"

// class Unit;

class Vampire : public Unit, public Observable {
    public:
        Vampire(const char* title, int hitPoints = HP_VAMPIRE, int damage = DMG_VAMPIRE, int resistCoeff = 1, bool isUndead = true);

        virtual ~Vampire();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
    
};

#endif //VAMPIRE_H