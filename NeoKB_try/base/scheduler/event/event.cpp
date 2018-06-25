#include "Event.h"

using namespace Base::Schedulers::Events;



Event::Event(const Event* e) {
	startTime = e->startTime;
	lifeTime = e->lifeTime;
}

Event::Event(MTO_FLOAT s, MTO_FLOAT l)
{
	startTime = s;
	lifeTime = l;
}

Event::Event(const Event &e)
{
	startTime = e.startTime;
	lifeTime = e.lifeTime;
}

int Event::SetStartTime(MTO_FLOAT s)
{
	startTime = s;
	return 0;
}

int Event::SetLifeTime(MTO_FLOAT l)
{
	lifeTime = l;
	return 0;
}

MTO_FLOAT Event::GetStartTime() const
{
	return startTime;
}

MTO_FLOAT Event::GetLifeTime() const
{
	return lifeTime;
}

bool Event::operator<(const Event & rhs) const
{
	return startTime < rhs.GetStartTime();
}

string Event::GetTypeName()
{
	return "Event";
}

Event * Event::Clone()
{
	return new Event(this);
}

template<typename T, typename U>
bool Event::CanCast(U * e)
{
	if (T* t = dynamic_cast< T* >(e)) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Event::CanCast()
{
	if (T* t = dynamic_cast< T* >(this)) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
T * Event::Cast()
{
	return dynamic_cast< T* >(this);
}
