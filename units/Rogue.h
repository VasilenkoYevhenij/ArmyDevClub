#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../attacks/RogueAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class RogueAttack;

class Rogue : public Unit, public Observable {
    public:
        Rogue(const char* title, int hitPoints = HP_ROGUE, int damage = DMG_ROGUE, int resistCoeff = 1, bool isUndead = false);

        virtual ~Rogue();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);

        virtual void turning();

};

#endif //ROGUE_H