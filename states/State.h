#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"
#include "../settings.cpp"

class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;
        int resistCoeff;
        bool isUndead;

        void _takeDamage(int dmg);

    public:
        State(const char* title, int hitPoints, int damage, int resistCoeff, bool isUndead);
        virtual ~State();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        int getResistCoeff() const;
        bool getIsUndead() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif // STATE_H
