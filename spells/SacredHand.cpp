#include "SacredHand.h"

SacredHand::SacredHand(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

SacredHand::~SacredHand() {}

void SacredHand::action(Unit* target) {
    target->addHitPoints(this->actionPoints);
}
