#ifndef UNIT_H
#define UNIT_H

// #include "../settings.cpp"
#include "../states/State.h"
#include "../attacks/BaseAttack.h"

class BaseAttack;

class Unit {
    protected:
        State* state;
        BaseAttack* ability;

    public:
        Unit(const char* title, int hitPoints = 100, int damage = 20, int resistCoeff = 1, bool isUndead = false);
        virtual ~Unit();

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
        void isDead();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void vampireTransition(Unit* enemy);
        virtual void werewolfTransition(Unit* enemy);
        virtual void transition(int marker);
        virtual void turning();
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H