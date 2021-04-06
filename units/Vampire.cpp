#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead) :
    Unit(title, hitPoints, damage, resistCoeff, isUndead), Observable(this) {
        this->ability = new VampireAttack(this);
}

Vampire::~Vampire() {}

void Vampire::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Vampire::update(Unit* observer) {
    this->detach(observer);
}

