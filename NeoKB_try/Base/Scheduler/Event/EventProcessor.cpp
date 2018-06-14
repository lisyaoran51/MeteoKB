#include "EventProcessor.h"


using namespace Base::Schedulers::Events;


template<class T>
int EventProcessor<T>::RegisterEvent(T * e)
{
	event = e;
	return 0;
}

template<class T>
MTO_FLOAT EventProcessor<T>::GetStartTime()
{
	return event->GetStartTime();
}

template<class T>
MTO_FLOAT EventProcessor<T>::GetTimeLeft()
{
	return event->GetLifeTime() - currerntTime;
}
