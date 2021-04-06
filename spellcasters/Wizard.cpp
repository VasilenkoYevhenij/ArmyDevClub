#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana)
    : SpellCaster(title, hitPoints, damage, resistCoeff, isUndead, mana), Observable(this) {
        this->magicAbility = new MagicAttack(this, new FireBall());

	FireBall* fireball = new FireBall();
	RakeNail* rakeNail = new RakeNail();
	BloodyArrow* bloodyArrow = new BloodyArrow();
	ChargedBolt* chargedBolt = new ChargedBolt();
	FlameArrow* flameArrow = new FlameArrow();
	HolyBolt* holyBolt = new HolyBolt();
	BurningHell* burningHell = new BurningHell();
	Heal* heal = new Heal(15);
	ModerateHeal* moderateHeal = new ModerateHeal(20);
	SacredHand* sacredHand = new SacredHand(25);

	this->addSpell(fireball);
	this->addSpell(rakeNail);
	this->addSpell(bloodyArrow);
	this->addSpell(chargedBolt);
	this->addSpell(flameArrow);
	this->addSpell(holyBolt);
	this->addSpell(burningHell);
	this->addSpell(heal);
	this->addSpell(moderateHeal);
	this->addSpell(sacredHand);
}

Wizard::~Wizard() {}

void Wizard::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Wizard::update(Unit* observer) {
    this->detach(observer);
}

void Wizard::transition(int marker) {
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

void Wizard::turning() {
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
