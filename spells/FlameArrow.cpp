#include "FlameArrow.h"

FlameArrow::FlameArrow(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

FlameArrow::~FlameArrow() {}

void FlameArrow::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
