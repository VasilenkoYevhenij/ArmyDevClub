#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../attacks/BaseAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class Werewolf : public Unit, public Observable {
    public:
        Werewolf(const char* title, int hitPoints = HP_WEREWOLF, int damage = DMG_WEREWOLF, int resistCoeff = 1, bool isUndead = false);
        virtual ~Werewolf();

        virtual void turning();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
};

#endif // WEREWOLF_H
