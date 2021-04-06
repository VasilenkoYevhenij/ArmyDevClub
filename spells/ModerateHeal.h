#ifndef MODERATEHEAL_H
#define MODERATEHEAL_H

#include "Spell.h"

class ModerateHeal : public Spell {
    public:
        ModerateHeal(int actionPoints = 40, int cost = 40, const std::string& spellName = "ModerateHeal");
        virtual ~ModerateHeal();
        virtual void action(Unit* target);
};

#endif // MODERATEHEAL_H
