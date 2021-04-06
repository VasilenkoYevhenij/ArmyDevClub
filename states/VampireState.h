#ifndef VAMPIRE_STATE_H
#define VAMPIRE_STATE_H

#include "State.h"

class VampireState : public State {
protected:
	const char* title;
    int hitPoints;
    int hitPointsLimit;
    int damage;
    int resistCoeff;
    bool isUndead;
public:
	VampireState(const char* title, int hitPoints = HP_VAMPIRE, int damage = DMG_VAMPIRE, int resistCoeff = RC_DEFFAULT, bool isUndead = true);
	virtual ~VampireState();
	
};
#endif // VAMPIRE_STATE_H