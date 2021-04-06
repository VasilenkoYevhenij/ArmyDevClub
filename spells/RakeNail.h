#ifndef RAKE_NAIL_H
#define RAKE_NAIL_H

#include "Spell.h"

class RakeNail : public Spell {
    public:
        RakeNail(int actionPoints = 50, int cost = 70, const std::string& spellName = "RakeNail");
        virtual ~RakeNail();
        virtual void action(Unit* target);
};

#endif // RAKE_NAIL_H
