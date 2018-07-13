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
MTO_FLOAT EventProcessor<T>::GetLifeTime()
{
	return event->GetLifeTime();
}

template<class T>
MTO_FLOAT EventProcessor<T>::GetTimeLeft()
{
	return event->GetLifeTime() - currentTime;
}

template<class T>
string EventProcessor<T>::GetTypeName()
{
	return string("EventProcessor");
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
template<typename U, typename V>
U * EventProcessor<T>::Cast(V * e)
{
	return dynamic_cast< U* >(e);
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
