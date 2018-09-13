#include "StartGameEvent.h"


using namespace Base::Schedulers::Events::GameEvents;


StartGameEvent::StartGameEvent(MTO_FLOAT s, MTO_FLOAT l) : GameEvent(s,l)
{
}

GameEventsType StartGameEvent::GetGameEventsType()
{
	return GameEventsType::Start;
}

string StartGameEvent::GetTypeName()
{
	return "StartGameEvent";
}
