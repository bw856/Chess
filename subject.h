#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>

class Observer;

class Subject {
	std::vector<std::shared_ptr<Observer>> observers;

	public:
	Subject();
	virtual ~Subject();
	void attach(std::shared_ptr<Observer> o);
	void detach(std::shared_ptr<Observer> o);
	virtual std::string getState(int x, int y) const = 0; // returns piece at pos(x, y)
	void notifyObservers();
};

#endif
