#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "observer.h"

class Subject {
	std::vector<std::shared_ptr<Observer>> observers;

	public:
	Subject();
	void attach(std::shared_ptr<Observer> o);
	void detach(std::shared_ptr<Observer> o);
	void notifyObservers();
	virtual char getState(int x, int y) const = 0; // returns piece at pos(x, y)
	virtual ~Subject() = default; // default dtor (since we use RAII pointers)
};

#endif
