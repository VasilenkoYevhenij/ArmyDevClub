#include "Heal.h"

Heal::Heal(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

Heal::~Heal() {}

void Heal::action(Unit* target) {
    target->addHitPoints(this->actionPoints);
}
