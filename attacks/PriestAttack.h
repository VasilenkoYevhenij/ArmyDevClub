#ifndef PRIEST_ATTACK_H
#define PRIEST_ATTACK_H

#include "MagicAttack.h"

class PriestAttack : public MagicAttack {
public:
	PriestAttack(SpellCaster* owner, Spell* spell);
	virtual ~PriestAttack();

	virtual void cast(Unit* enemy);
	virtual void changeSpell(Spell* newSpell);
};

#endif // PRIEST_ATTACK_H