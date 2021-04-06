#ifndef SPELL_H
#define SPELL_H

#include "../units/Unit.h"

class Spell {
	protected:
		int cost;
		int actionPoints;
		std::string spellName;

	public:
		Spell(int actionPoints, int cost, const std::string& spellName = "Spell");
		virtual ~Spell();

		int getActionPoints() const;
        int getCost() const;
        const std::string& getSpellName() const;

        virtual void action(Unit* target) = 0;
};
#endif //SPELL_H