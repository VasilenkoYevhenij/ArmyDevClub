#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class Wizard : public SpellCaster, public Observable {
    public:
        Wizard(const char* title, int hitPoints = HP_WIZARD, int damage = DMG_WIZARD, int resistCoeff = 1, bool isUndead = false, int mana = MP_WIZARD);
        virtual ~Wizard();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);
        virtual void turning();
};

#endif // WIZARD_H
