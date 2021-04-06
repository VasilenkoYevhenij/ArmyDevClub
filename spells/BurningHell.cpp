#include "BurningHell.h"

BurningHell::BurningHell(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

BurningHell::~BurningHell() {}

void BurningHell::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
