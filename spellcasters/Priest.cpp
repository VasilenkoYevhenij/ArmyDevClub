#include "Priest.h"

Priest::Priest(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana)
    : SpellCaster(title, hitPoints, damage, resistCoeff, isUndead, mana), Observable(this) {
        this->magicAbility = new PriestAttack(this, new Heal());

	BloodyArrow* bloodyArrow = new BloodyArrow(15);
	ChargedBolt* chargedBolt = new ChargedBolt(13);
	HolyBolt* holyBolt = new HolyBolt(10);
	Heal* heal = new Heal();
	ModerateHeal* moderateHeal = new ModerateHeal();
	SacredHand* sacredHand = new SacredHand();

	this->addSpell(bloodyArrow);
	this->addSpell(chargedBolt);
	this->addSpell(holyBolt);
	this->addSpell(heal);
	this->addSpell(moderateHeal);
	this->addSpell(sacredHand);
}

Priest::~Priest() {}

void Priest::attack(Unit* enemy) {
    this->ability->attack(enemy);

    if (this->getDamage() == DMG_PRIEST && enemy->getIsUndead() ) {
        enemy->takeDamage(DMG_PRIEST);
    }
}

void Priest::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Priest::update(Unit* observer) {
    this->detach(observer);
}

void Priest::transition(int marker) {
    const char* name = this->getTitle();

    delete(this->magicAbility);
    delete(this->state);
    delete(this->ability);

    if ( marker == HP_VAMPIRE ) {
       this->state = new VampireState(name);
       this->ability = new VampireAttack(this);
       this->magicState = new MagicState(0);
    } else {
        this->state = new WerewolfState(name);
        this->ability = new WerewolfAttack(this);
        this->magicState = new MagicState(0);
    }
}

void Priest::turning() {
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

