#include "MagicAttack.h"

MagicAttack::MagicAttack(SpellCaster* owner, Spell* spell)
    : owner(owner), spell(spell) {}

MagicAttack::~MagicAttack() {
    delete(this->spell);
}

void MagicAttack::changeSpell(Spell* newSpell) {
    delete(this->spell);
    this->spell = newSpell;
}

void MagicAttack::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(enemy);
}
