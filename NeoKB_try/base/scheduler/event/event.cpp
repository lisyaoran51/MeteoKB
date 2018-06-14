#include "Event.h"

using namespace Base::Schedulers::Events;

Event::Event(MTO_FLOAT s, MTO_FLOAT l)
{
	startTime = s;
	lifeTime = l;
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
