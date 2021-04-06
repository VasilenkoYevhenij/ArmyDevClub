#include "RakeNail.h"

RakeNail::RakeNail(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

RakeNail::~RakeNail() {}

void RakeNail::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
