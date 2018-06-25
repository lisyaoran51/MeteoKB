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

template<class T>
template<typename U, typename V>
bool EventProcessor<T>::CanCast(V * e)
{
	if (U* t = dynamic_cast< U* >(e)) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
template<typename U>
bool EventProcessor<T>::CanCast()
{
	if (U* t = dynamic_cast< U* >(this)) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
template<typename U>
U* EventProcessor<T>::Cast()
{
	return dynamic_cast< U* >(this);
}
