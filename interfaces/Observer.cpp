#include "Observer.h"

Observer::Observer(Unit* unit) {
    this->owner = unit;
}

Observer::~Observer() {
    this->notify();
}

void Observer::attach(Unit* observable) {
	std::string name = observable->getTitle();
    
    if ( observables.find(name) == observables.end() ) {
        observables.insert(std::pair<std::string, Unit*>(name, observable));
	}
}

void Observer::detach(Unit* observable) {
	std::string name = observable->getTitle();
    
    observables.erase(name);
}

void Observer::notify() {
	std::map<std::string, Unit*>::iterator it = this->observables.begin();
    
    for ( ; it != this->observables.end(); it++ ) {
        (it->second)->update(this->owner);
    }
}