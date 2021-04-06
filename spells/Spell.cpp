#include "Spell.h"

Spell::Spell(int actionPoints, int cost, const std::string& spellName)
    : actionPoints(actionPoints), cost(cost), spellName(spellName) {}

Spell::~Spell() {}

int Spell::getActionPoints() const {
    return this->actionPoints;
}

int Spell::getCost() const {
    return this->cost;
}

const std::string& Spell::getSpellName() const {
	return this->spellName;
}
