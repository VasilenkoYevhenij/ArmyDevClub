#include "ModerateHeal.h"

ModerateHeal::ModerateHeal(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

ModerateHeal::~ModerateHeal() {}

void ModerateHeal::action(Unit* target) {
    target->addHitPoints(this->actionPoints);
}
