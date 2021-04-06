#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../units/Unit.h"
#include "../attacks/MagicAttack.h"
#include "../states/MagicState.h"
#include "../spells/FireBall.h"
#include "../spells/Heal.h"
#include "../spells/Spell.h"
#include "../spells/BloodyArrow.h"
#include "../spells/BurningHell.h"
#include "../spells/ChargedBolt.h"
#include "../spells/FlameArrow.h"
#include "../spells/HolyBolt.h"
#include "../spells/ModerateHeal.h"
#include "../spells/RakeNail.h"
#include "../spells/SacredHand.h"
#include <map>
// #include "../ability/DefaultAbility.h"

class MagicAttack;

class SpellCaster: public Unit {
    protected:
        MagicState* magicState;
        MagicAttack* magicAbility;
        std::map<std::string, Spell*>* spellBook;

    public:
        SpellCaster(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;

        void addMana(int extra);
        void spendMana(int cost);

        void addSpell(Spell* spell);
        void changeSpell(Spell* newSpell);
        virtual void cast(Unit* enemy);
    };

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster);

#endif // SPELL_CASTER_H
