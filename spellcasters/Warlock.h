#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../units/Demon.h"
#include <list>
#include "../interfaces/Observable.h"
#include "../attacks/VampireAttack.h"
#include "../states/VampireState.h"
#include "../attacks/WerewolfAttack.h"
#include "../states/WerewolfState.h"



class Warlock : public SpellCaster, public Observable {
	protected:
			std::list<Demon*>* demons;

    public:
        Warlock(const char* title, int hitPoints = HP_WIZARD, int damage = DMG_WARLOCK, int resistCoeff = RC_DEFFAULT, bool isUndead = false, int mana = MP_WARLOCK);
        virtual ~Warlock();

        void DemonsAttack(Unit* enemy);
        Demon* CreateDemon();

        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);

        virtual void transition(int marker);
        virtual void turning();
};

#endif // WARLOCK_H
