#include "HolyBolt.h"

HolyBolt::HolyBolt(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

HolyBolt::~HolyBolt() {}

void HolyBolt::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
