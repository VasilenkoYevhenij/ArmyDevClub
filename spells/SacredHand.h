#ifndef SACREDHAND_H
#define SACREDHAND_H

#include "Spell.h"

class SacredHand : public Spell {
    public:
        SacredHand(int actionPoints = 50, int cost = 75, const std::string& spellName = "SacredHand");
        virtual ~SacredHand();
        virtual void action(Unit* target);
};

#endif // SACREDHAND_H
