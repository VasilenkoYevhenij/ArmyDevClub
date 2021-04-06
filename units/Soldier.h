#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../attacks/BaseAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"


class Soldier : public Unit, public Observable {
    public:
        Soldier(const char* title, int hitPoints = HP_SOLDIER, int damage = DMG_SOLDIER, int resistCoeff = 1, bool isUndead = false);
        virtual ~Soldier();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);

        virtual void turning();
};

#endif // SOLDIER_H
