#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../attacks/PriestAttack.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class Priest : public SpellCaster, public Observable {
    public:
        Priest(const char* title, int hitPoints = HP_PRIEST, int damage = DMG_PRIEST, int resistCoeff = 1, bool isUndead = false, int mana = MP_PRIEST);
        virtual ~Priest();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);
        virtual void turning();

        virtual void attack(Unit* enemy);
};

#endif // PRIEST_H
