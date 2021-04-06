#ifndef CHARGED_BOLT_H
#define CHARGED_BOLT_H

#include "Spell.h"

class ChargedBolt : public Spell {
    public:
        ChargedBolt(int actionPoints = 26, int cost = 30, const std::string& spellName = "ChargedBolt");
        virtual ~ChargedBolt();
        virtual void action(Unit* target);
};

#endif // CHARGED_BOLT_H
