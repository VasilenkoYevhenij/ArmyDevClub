#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../interfaces/Observer.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"

class Necromancer : public SpellCaster, public Observer {
    public:
        Necromancer(const char* title, int hitPoints = HP_NECROMANCER, int damage = DMG_NECROMANCER, int resistCoeff = RC_DEFFAULT, bool isUndead = true, int mana = MP_NECROMANCER);
        virtual ~Necromancer();

        virtual void update(Unit* observer);

        virtual void attack(Unit* enemy);

        virtual void transition(int marker);
        virtual void turning();
};

#endif // NECROMANCER_H
