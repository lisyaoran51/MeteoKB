#include "scheduler.h"


using namespace Base::Scheduler;





Scheduler::Scheduler()
{
	eventProcessors = new vector<EventProcessor*>();
}

Scheduler::~Scheduler()
{
	delete eventProcessors;
}

int Scheduler::Add(EventProcessor * ep)
{
	eventProcessors->push_back(ep);

	return 0;
}

int Scheduler::RegisterHandler(int(*h)(EventProcessor *))
{
	deliverHandler = h;
	return 0;
}

int Scheduler::Elapse(MTO_FLOAT elapsedTime) {

	currentTime += elapsedTime;

	while ((*eventProcessors->back())->GetStartTime() < currentTime) {
		deliverHandler(eventProcessors->pop_back());
	}

}