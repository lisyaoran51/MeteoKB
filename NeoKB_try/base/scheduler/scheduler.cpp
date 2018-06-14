#include "scheduler.h"


using namespace Base::Schedulers;





Scheduler::Scheduler(): RegisterType("Scheduler")
{
	eventProcessors = new vector<EventProcessor<Event>*>();
}

Scheduler::~Scheduler()
{
	delete eventProcessors;
}

int Scheduler::Add(EventProcessor<Event> * ep)
{
	eventProcessors->push_back(ep);

	return 0;
}

int Scheduler::AddRange(vector<EventProcessor<Event>*>* eps)
{
	for (int i = 0; i < eps->size(); i++) {
		Add(eps->at(i));
	}
	return 0;
}

int Scheduler::RegisterHandler(function<int(EventProcessor<Event>*)> dh)
{
	deliverHandler = dh;
	return 0;
}

int Scheduler::Elapse(MTO_FLOAT elapsedTime) {

	if (elapsedTime == -1) {
		// 遊戲還沒開始時事-1，之後變0代表遊戲開始
		currentTime = 0;
	}
	
	currentTime += elapsedTime;

	while (eventProcessors->back()->GetStartTime() < currentTime) {
		deliverHandler(eventProcessors->back());
		eventProcessors->pop_back();
	}
}