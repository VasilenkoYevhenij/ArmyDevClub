#ifndef BASEATTACK_H
#define BASEATTACK_H

#include "../units/Unit.h"

class Unit;

class BaseAttack {
    protected:
        Unit* owner;

    public:
        BaseAttack(Unit* owner);
        virtual ~BaseAttack();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void vampireTransition(Unit* enemy);
        virtual void werewolfTransition(Unit* enemy);

        virtual void turning();
};

#endif // BASEATTACK_H
