#include "Event.h"

using namespace Base::Schedulers::Events;

Event::Event(MTO_FLOAT s, MTO_FLOAT l)
{
	startTime = s;
	lifeTime = l;
}

MTO_FLOAT Event::GetStartTime()
{
	return startTime;
}

MTO_FLOAT Event::GetLifeTime()
{
	return lifeTime;
}

