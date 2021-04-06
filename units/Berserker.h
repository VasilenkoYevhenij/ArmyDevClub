#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../attacks/BaseAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"


class Berserker : public Unit, public Observable {
    public:
        Berserker(const char* title, int hitPoints = HP_BERSERKER, int damage = DMG_BERSERKER, int resistCoeff = RC_BERSERKER, bool isUndead = false);

        virtual ~Berserker();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);
        virtual void turning();

};

#endif // BERSERKER_H
