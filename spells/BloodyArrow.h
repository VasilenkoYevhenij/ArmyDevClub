#ifndef BLOODY_ARROW_H
#define BLOODY_ARROW_H

#include "Spell.h"

class BloodyArrow : public Spell {
    public:
        BloodyArrow(int actionPoints = 30, int cost = 25, const std::string& spellName = "BloodyArrow");
        virtual ~BloodyArrow();
        virtual void action(Unit* target);
};

#endif // BLOODY_ARROW_H
