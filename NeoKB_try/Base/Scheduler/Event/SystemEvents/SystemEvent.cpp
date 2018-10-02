#include "SystemEvent.h"


using namespace Base::Schedulers::Events::SystemEvents;



SystemEvent::SystemEvent(MTO_FLOAT s, MTO_FLOAT l) : Event(s,l)
{
}

string SystemEvent::GetTypeName()
{
	return "SystemEvent";
}
