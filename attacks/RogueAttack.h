#ifndef ROGUEATTACK_H
#define ROGUEATTACK_H

#include "BaseAttack.h"

class RogueAttack : public BaseAttack {
    public:
        RogueAttack(Unit* owner);
        virtual ~RogueAttack();

        virtual void attack(Unit* enemy);
};

#endif //ROGUEATTACK_H