#include "FireBall.h"

FireBall::FireBall(int actionPoints, int cost, const std::string& spellName) : Spell(actionPoints, cost, spellName) {}

FireBall::~FireBall() {}

void FireBall::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}
