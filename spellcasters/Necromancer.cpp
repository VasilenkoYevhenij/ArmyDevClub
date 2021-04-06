#include "Necromancer.h"

Necromancer::Necromancer(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana)
    : SpellCaster(title, hitPoints, damage, resistCoeff, isUndead, mana), Observer(this) {
        this->magicAbility = new MagicAttack(this, new FireBall());

	FireBall* fireball = new FireBall();
	RakeNail* rakeNail = new RakeNail();
	BloodyArrow* bloodyArrow = new BloodyArrow();
	Heal* heal = new Heal(15);
	ModerateHeal* moderateHeal = new ModerateHeal(20);
	SacredHand* sacredHand = new SacredHand(25);


	this->addSpell(fireball);
	this->addSpell(rakeNail);
	this->addSpell(bloodyArrow);
	this->addSpell(heal);
	this->addSpell(moderateHeal);
	this->addSpell(sacredHand);
}

Necromancer::~Necromancer() {
    delete this->ability;
}
void Necromancer::update(Unit* observable) {
	this->owner->addHitPoints(observable->getHitPointsLimit() / 7);
	this->detach(observable);
}

void Necromancer::attack(Unit* enemy) {
	this->ability->attack(enemy);
	
	if (this->getHitPointsLimit() == HP_NECROMANCER ) {
		this->attach(enemy);
    	enemy->sign(this);
    }
    
}

void Necromancer::transition(int marker) {
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

void Necromancer::turning() {
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
