#ifndef MAGIC_ATTACK_H
#define MAGIC_ATTACK_H

#include "../spells/Spell.h"
#include "../spellcasters/SpellCaster.h"

class SpellCaster;

class MagicAttack {
    protected:
        SpellCaster* owner;
        Spell* spell;

    public:
        MagicAttack(SpellCaster* owner, Spell* spell);
        virtual ~MagicAttack();
        
        virtual void changeSpell(Spell* newSpell);
        virtual void cast(Unit* enemy);
};

#endif // MAGIC_ATTACK_H
