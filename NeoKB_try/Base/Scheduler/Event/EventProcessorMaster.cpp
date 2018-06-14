#include "EventProcessorMaster.h"

using namespace Base::Schedulers::Events;



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

int EventProcessorMaster::Clean()
{
	eventProcessors->clear();
	return 0;
}

int EventProcessorMaster::processEvent(MTO_FLOAT elapsedTime)
{
	for (int i = 0; i < eventProcessors->size(); i++) {
		eventProcessors->at(i)->Elapse(elapsedTime);
	}
	return 0;
}

int EventProcessorMaster::cleanEndedEvent()
{

	for (vector<EventProcessor<Event>*>::iterator i = eventProcessors->begin(); i != eventProcessors->end(); i++)
	{
		if ((*i)->GetTimeLeft() <= 0) {
			// TODO:
			// eventProcessors erase i �����D���g
			i = eventProcessors->erase(i);
			// �����R���H��|�������V�U�@�Ӥ����A�ҥH�n���ߦ^��
			i--;
		}
	}

	return 0;
}

int EventProcessorMaster::Elapse(MTO_FLOAT elapsedTime)
{
	if (elapsedTime == -1) {
		currentTime = 0;
		return;
	}


	processEvent(elapsedTime);
	cleanEndedEvent();
	return 0;
}

