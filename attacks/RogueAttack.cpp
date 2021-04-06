#include "RogueAttack.h"

RogueAttack::RogueAttack(Unit* owner): BaseAttack(owner) {}
RogueAttack::~RogueAttack() {};

void RogueAttack::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
}