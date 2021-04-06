#ifndef OBSERVER_H
#define OBSERVER_H

#include "../units/Unit.h"
#include <map>
#include "Observable.h"

class Observable;

class Observer {
	protected:
		Unit* owner;
		std::map<std::string, Unit*> observables;
	public:
		Observer(Unit* unit);
		virtual ~Observer();

		void attach(Unit* observable);
		void detach(Unit* observable);

		virtual void notify();
	
};

#endif // OBSERVER_H