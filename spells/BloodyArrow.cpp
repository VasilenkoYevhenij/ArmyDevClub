#include "BloodyArrow.h"

BloodyArrow::BloodyArrow(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

BloodyArrow::~BloodyArrow() {}

void BloodyArrow::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
