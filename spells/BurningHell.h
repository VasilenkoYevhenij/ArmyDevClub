#ifndef BURNING_HELL_H
#define BURNING_HELL_H

#include "Spell.h"

class BurningHell : public Spell {
    public:
        BurningHell(int actionPoints = 60, int cost = 80, const std::string& spellName = "BurningHell");
        virtual ~BurningHell();
        virtual void action(Unit* target);
};

#endif // BURNING_HELL_H
