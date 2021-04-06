#include "ChargedBolt.h"

ChargedBolt::ChargedBolt(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

ChargedBolt::~ChargedBolt() {}

void ChargedBolt::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
