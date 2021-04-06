#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana)
    : Unit(title, hitPoints, damage, resistCoeff, isUndead), magicState(new MagicState(mana)) {
        this->spellBook = new std::map<std::string, Spell*>();
    }

SpellCaster::~SpellCaster() {
    std::map<std::string, Spell*>::iterator it = spellBook->begin();
    
    for ( ; it != spellBook->end(); it++ ) {
        delete it->second;
    }
    delete(this->magicState);
    delete(this->magicAbility);
}

int SpellCaster::getMana() const {
    return this->magicState->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

void SpellCaster::addMana(int extra) {
    this->magicState->addMana(extra);
}

void SpellCaster::spendMana(int cost) {
    this->magicState->spendMana(cost);
}

void SpellCaster::addSpell(Spell* spell) {
    if ( this->spellBook->find(spell->getSpellName()) == this->spellBook->end() ) {
        this->spellBook->insert(std::pair<std::string, Spell*>(spell->getSpellName(), spell));
    }
}

void SpellCaster::changeSpell(Spell* newSpell) {
    std::map<std::string, Spell*>::iterator it;
    
    it = this->spellBook->find(newSpell->getSpellName());
    
    if ( it == this->spellBook->end() ) {
        return;
    }
    this->magicAbility->changeSpell(it->second);
}

void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster) {
    out << "spellcaster: " << spellcaster.getTitle() << "\nhpLimit: " << spellcaster.getHitPointsLimit() << "\ncurrent hp: " << spellcaster.getHitPoints() << "\ncurrent mp: " << spellcaster.getMana();

    return out;
}
