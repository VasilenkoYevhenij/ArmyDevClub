#ifndef FLAME_ARROW_H
#define FLAME_ARROW_H

#include "Spell.h"

class FlameArrow : public Spell {
    public:
        FlameArrow(int actionPoints = 34, int cost = 40, const std::string& spellName = "FlameArrow");
        virtual ~FlameArrow();
        virtual void action(Unit* target);
};

#endif // FLAME_ARROW_H
