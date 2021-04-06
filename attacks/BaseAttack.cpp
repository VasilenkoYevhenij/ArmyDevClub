#include "BaseAttack.h"

BaseAttack::BaseAttack(Unit* owner): owner(owner) {}
BaseAttack::~BaseAttack() {}

void BaseAttack::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
};

void BaseAttack::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / 2);
};

void BaseAttack::vampireTransition(Unit* enemy) {};

void BaseAttack::werewolfTransition(Unit* enemy) {};

void BaseAttack::turning() {};