#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead): 
    Unit(title, hitPoints, damage, resistCoeff, isUndead), Observable(this) {
        this->ability = new WerewolfAttack(this);
    }

Werewolf::~Werewolf() {}

void Werewolf::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Werewolf::update(Unit* observer) {
    this->detach(observer);
}

void Werewolf::turning() {
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
