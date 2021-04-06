#include "WerewolfState.h"

WerewolfState::WerewolfState(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead) : State(title, hitPoints, damage, resistCoeff, isUndead) {};

WerewolfState::~WerewolfState() {};