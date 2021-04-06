#include "VampireState.h"

VampireState::VampireState(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead) : State(title, hitPoints, damage, resistCoeff, isUndead) {};

VampireState::~VampireState() {};