#include "EventProcessor.h"


using namespace Base::Scheduler::Event;


template<class T>
int EventProcessor<T>::RegisterEvent(T * e)
{
	event = e;
	return 0;
}