#include "units/Unit.h"
#include "units/Soldier.h"
#include "units/Rogue.h"
#include "units/Vampire.h"
#include "units/Werewolf.h"
#include "units/Berserker.h"
#include "Spellcasters/Spellcaster.h"
#include "Spellcasters/Wizard.h"
#include "Spellcasters/Healer.h"
#include "Spellcasters/Priest.h"
#include "units/Demon.h"
#include "Spellcasters/Warlock.h"
#include "Spellcasters/Necromancer.h"
#include "interfaces/Observer.h"
#include "interfaces/Observable.h"


int main() {

	FireBall* fireball = new FireBall();
	RakeNail* rakeNail = new RakeNail();
	BloodyArrow* bloodyArrow = new BloodyArrow();
	ChargedBolt* chargedBolt = new ChargedBolt();
	FlameArrow* flameArrow = new FlameArrow();
	HolyBolt* holyBolt = new HolyBolt();
	BurningHell* burningHell = new BurningHell();
	Heal* heal = new Heal();
	ModerateHeal* moderateHeal = new ModerateHeal();
	SacredHand* sacredHand = new SacredHand();

    Soldier* s2 = new Soldier("Soldier");
    Healer* h1 = new Healer("Healer");
    Wizard* wi1 = new Wizard("Wizard");
    Warlock* warlock = new Warlock("Warlock");
    Necromancer* necr = new Necromancer("Necromancer");
    Priest* p1 = new Priest("Priest");
    Vampire* v1 = new Vampire("Vampire");
    Werewolf* w1 = new Werewolf("Werewolf");
    Berserker* b1 = new Berserker("Berserker");
    Rogue* r1 = new Rogue("Rogue");
    Demon* d1 = warlock->CreateDemon();

	std::cout << "UNITS\n" << std::endl;
	std::cout << *s2 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *v1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *w1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *d1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *r1 << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "SPELLCASTERS\n" << std::endl;
	std::cout << *wi1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *h1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *necr << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << *warlock << std::endl;

    return 0;
}