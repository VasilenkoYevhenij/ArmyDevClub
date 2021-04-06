#include "WerewolfAttack.h"

WerewolfAttack::WerewolfAttack(Unit* owner): BaseAttack(owner) {}
WerewolfAttack::~WerewolfAttack() {}

void WerewolfAttack::werewolfTransition(Unit* enemy) {
	enemy->ensureIsAlive();
	if ( enemy->getHitPointsLimit() == HP_WEREWOLF || enemy->getHitPointsLimit() == HP_WOLF || enemy->getHitPointsLimit() == HP_VAMPIRE ) {
		throw CantBeTurnedException();
	} 
	else {
		enemy->transition(this->owner->getHitPointsLimit());
    }
}
