#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"


class Healer : public SpellCaster, public Observable {
    public:
        Healer(const char* title, int hitPoints = HP_HEALER, int damage = DMG_HEALER, int resistCoeff = 1, bool isUndead = false, int mana = MP_HEALER);
        virtual ~Healer();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transition(int marker);
        virtual void turning();
};

#endif // HEALER_H
