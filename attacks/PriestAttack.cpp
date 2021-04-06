#include "PriestAttack.h"

PriestAttack::PriestAttack(SpellCaster* owner, Spell* spell): MagicAttack(owner, spell) {}
PriestAttack::~PriestAttack() {};

void PriestAttack::changeSpell(Spell* newSpell) {
    delete(this->spell);
    this->spell = newSpell;
}

void PriestAttack::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(enemy);


    if ( enemy->getIsUndead() ) {
    	this->spell->action(enemy);
    }
}



