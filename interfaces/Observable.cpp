#include "Observable.h"

Observable::Observable(Unit* unit) {
	this->owner = unit;
}

Observable::~Observable() {
    this->notify();
}

void Observable::attach(Unit* observer) {
	std::string name = observer->getTitle();
    
    if ( observers.find(name) == observers.end() ) {
        observers.insert(std::pair<std::string, Unit*>(name, observer));
    }
}

void Observable::detach(Unit* observer) {
	std::string name = observer->getTitle();
    
    observers.erase(name);
}

void Observable::notify() {
	std::map<std::string, Unit*>::iterator it = this->observers.begin();
    
    for ( ; it != this->observers.end(); it++ ) {
        (it->second)->update(this->owner);
    }
}