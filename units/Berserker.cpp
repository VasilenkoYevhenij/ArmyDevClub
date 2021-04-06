#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead): 
    Unit(title, hitPoints, damage, resistCoeff, isUndead), Observable(this) {
        this->ability = new BaseAttack(this);
    }
Berserker::~Berserker() {}

void Berserker::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Berserker::update(Unit* observer) {
    this->detach(observer);
}

void Berserker::transition(int marker) {
    const char* name = this->getTitle();

	delete(this->state);
	delete(this->ability);

    if ( marker == HP_VAMPIRE ) {
	   this->state = new VampireState(name);
	   this->ability = new VampireAttack(this);
    } else {
        this->state = new WerewolfState(name);
        this->ability = new WerewolfAttack(this);
    }
}

void Berserker::turning() {
    if ( this->getHitPointsLimit() != HP_WEREWOLF && this->getHitPointsLimit() !=  HP_WOLF ) {
        throw CantBeTurnedException();
    }

    const char* name = this->getTitle();

    if ( this->getHitPointsLimit() == HP_WEREWOLF ) {
        delete(this->state);
        this->state = new State(name, HP_WOLF, DMG_WOLF, RC_WOLF, false);
    } else if ( this->getHitPointsLimit() == HP_WOLF ) {
        delete(this->state);
        this->state = new WerewolfState(name);
    }

}