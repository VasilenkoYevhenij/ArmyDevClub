#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal : public Spell {
    public:
        Heal(int actionPoints = 30, int cost = 30, const std::string& spellName = "Heal");
        virtual ~Heal();
        virtual void action(Unit* target);
};

#endif // HEAL_H
