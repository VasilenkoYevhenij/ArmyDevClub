#ifndef VAMPIREATTACK_H
#define VAMPIREATTACK_H

#include "BaseAttack.h"
#include "../units/Vampire.h"

class VampireAttack : public BaseAttack {
    public:
        VampireAttack(Unit* owner);
        virtual ~VampireAttack();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        void hpSteal(int hp);

        virtual void vampireTransition(Unit* enemy);
};

#endif //VAMPIREATTACK_H