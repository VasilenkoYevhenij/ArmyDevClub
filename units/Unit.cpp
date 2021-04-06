#include "Unit.h"

Unit::Unit(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead) {
    this->state = new State(title, hitPoints, damage, resistCoeff, isUndead);
    this->ability = new BaseAttack(this);
}

Unit::~Unit() {
    delete(this->state);
    delete(this->ability);
}

void Unit::isDead() {
    if ( this->getHitPoints() == 0 ) {
        std::cout << this->getTitle() << " is dead." << std::endl;
        delete this;
        throw OutOfHitPointsException();
    }
}

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

int Unit::getResistCoeff() const {
    return this->state->getResistCoeff();
}

bool Unit::getIsUndead() const {
    return this->state->getIsUndead();
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    this->isDead();
    this->state->takeDamage(dmg);
    this->isDead();
}

void Unit::takeMagicDamage(int dmg) {
    this->isDead();
    this->state->takeMagicDamage(dmg);
    this->isDead();
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}
void Unit::transition(int marker) {

}

void Unit::vampireTransition(Unit* enemy) {
    this->ability->vampireTransition(enemy);
}

void Unit::werewolfTransition(Unit* enemy) {
    this->ability->werewolfTransition(enemy);
}

void Unit::turning() {
    this->ability->turning();
}

void Unit::sign(Unit* enemy) {

}

void Unit::update(Unit* observer) {

}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "unit: " << unit.getTitle() << "\nhpLimit: " << unit.getHitPointsLimit() << "\ncurrent hp: " << unit.getHitPoints();

    return out;
}
