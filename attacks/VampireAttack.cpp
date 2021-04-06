#include "VampireAttack.h"

VampireAttack::VampireAttack(Unit* owner): BaseAttack(owner) {}
VampireAttack::~VampireAttack() {}

void VampireAttack::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
    hpSteal(this->owner->getDamage() / 3);
}

void VampireAttack::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / 2);
    hpSteal(this->owner->getDamage() / 4);
}

void VampireAttack::hpSteal(int hp) {
    this->owner->addHitPoints(hp);
}

void VampireAttack::vampireTransition(Unit* enemy) {
	enemy->ensureIsAlive();
	if ( enemy->getHitPointsLimit() == HP_WEREWOLF || enemy->getHitPointsLimit() == HP_WOLF || enemy->getHitPointsLimit() == HP_VAMPIRE ) {
		throw CantBeTurnedException();
	} 
	else {
		enemy->transition(this->owner->getHitPointsLimit());
    }
}
