#ifndef WEREWOLF_ATTACK_H
#define WEREWOLF_ATTACK_H

#include "BaseAttack.h"
#include "../units/Werewolf.h"

class WerewolfAttack : public BaseAttack {
    public:
        WerewolfAttack(Unit* owner);
        virtual ~WerewolfAttack();

        virtual void werewolfTransition(Unit* enemy);
   
};

#endif //WEREWOLF_ATTACK_H