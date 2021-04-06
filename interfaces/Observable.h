#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "../units/Unit.h"
#include "Observer.h"
#include <map>

class Observer;

class Observable {
	protected:
		Unit* owner;
		std::map<std::string, Unit*> observers;
	public:
		Observable(Unit* unit);
		virtual ~Observable();

		void attach(Unit* observer);
        void detach(Unit* observer);

        virtual void notify();
	
};
#endif // OBSERVABLE_H