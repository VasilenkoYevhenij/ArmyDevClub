#include "Warlock.h"

Warlock::Warlock(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead, int mana)
    : SpellCaster(title, hitPoints, damage, resistCoeff, isUndead, mana), Observable(this) {
        this->magicAbility = new MagicAttack(this, new FireBall());
        this->demons = new std::list<Demon*>();

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

Warlock::~Warlock() {
	std::list<Demon*>::iterator it = this->demons->begin();
    
    for ( ; it != this->demons->end(); it++) {
        delete *it;
    }
    
    delete this->demons;
    delete this->ability;
}

void Warlock::DemonsAttack(Unit* enemy) {
	if ( enemy->getTitle() == this->getTitle() ) {
        throw CantAttackCreatorException();
    }
    std::list<Demon*>::iterator it;
    
    for ( it = this->demons->begin(); it != this->demons->end(); it++ ) {
        (*it)->attack(enemy);
    }
}
Demon* Warlock::CreateDemon() {
	Demon* demon = new Demon("Demon");
	this->demons->push_back(demon);
	this->magicState->spendMana(50);

	return demon;
}

void Warlock::sign(Unit* enemy) {
    if ( enemy->getHitPointsLimit() == HP_NECROMANCER ) {
        this->attach(enemy);
    } else {
    throw CantSignException();
    }
}
void Warlock::update(Unit* observer) {
    this->detach(observer);
}

void Warlock::transition(int marker) {
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

void Warlock::turning() {
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
