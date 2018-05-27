#include "EventProcessorMaster.h"

using namespace Base::Scheduler::Event;



int EventProcessorMaster::ReceiveEventProcessor(EventProcessor<Event>* ep)
{
	eventProcessors->push_back(ep);
	return 0;
}

int EventProcessorMaster::RegisterMap(Map * m)
{
	map = m;
	return 0;
}

int EventProcessorMaster::processEvent(MTO_FLOAT elapsedTime)
{
	for (int i = 0; i < eventProcessors->size(); i++) {
		(*eventProcessors->at(i))->Elapse(elapsedTime);
	}
	return 0;
}

int EventProcessorMaster::cleanEndedEvent()
{
	for (int i = 0; i < eventProcessors->size(); i++) {
		if ((*eventProcessors->at(i))->GetTimeLeft() < 0) {
			// TODO:
			// eventProcessors erase i 不知道怎麼寫
		}
	}

	return 0;
}

int EventProcessorMaster::Elapse(MTO_FLOAT elapsedTime)
{
	processEvent(elapsedTime);
	cleanEndedEvent();
	return 0;
}

