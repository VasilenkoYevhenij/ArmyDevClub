#ifndef WEREWOLF_STATE_H
#define WEREWOLF_STATE_H

#include "State.h"

class WerewolfState : public State {
protected:
	const char* title;
    int hitPoints;
    int hitPointsLimit;
    int damage;
    int resistCoeff;
    bool isUndead;
public:
	WerewolfState(const char* title, int hitPoints = HP_WEREWOLF, int damage = DMG_WEREWOLF, int resistCoeff = RC_DEFFAULT, bool isUndead = false);
	virtual ~WerewolfState();
	
};
#endif // WEREWOLF_STATE_H