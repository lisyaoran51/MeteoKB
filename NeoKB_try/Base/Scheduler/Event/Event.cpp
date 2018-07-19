#include "Event.h"

using namespace Base::Schedulers::Events;



Event::Event(const Event* e) {
	startTime = e->startTime;
	lifeTime = e->lifeTime;
}

Event::Event()
{
	throw logic_error("int Event::Event : This constructor is for template constraint. Cannot be executed.");
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


