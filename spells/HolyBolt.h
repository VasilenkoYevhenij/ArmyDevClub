#ifndef HOLY_BOLT_H
#define HOLY_BOLT_H

#include "Spell.h"

class HolyBolt : public Spell {
    public:
        HolyBolt(int actionPoints = 20, int cost = 30, const std::string& spellName = "HolyBolt");
        virtual ~HolyBolt();
        virtual void action(Unit* target);
};

#endif // HOLY_BOLT_H
