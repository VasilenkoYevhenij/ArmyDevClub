#ifndef DEMON_H
#define DEMON_H

#include "Unit.h"
#include "../attacks/BaseAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class Demon : public Unit, public Observable {
    public:
        Demon(const char* title, int hitPoints = HP_DEMON, int damage = DMG_DEMON, int resistCoeff = RC_DEFFAULT, bool isUndead = false);
        virtual ~Demon();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);

        virtual void turning();
};

#endif // DEMON_H
