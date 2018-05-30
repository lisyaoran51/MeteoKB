#include "MeteorRulesetExecutor.h"

using namespace Meteor::Ruleset;
using namespace Base::Scheduler::Event;

Playfield* MeteorRulesetExecutor::create_playfield()
{

	InstanceCreator<MtoObject> iCreator = InstanceCreator<MtoObject>::GetInstance();
MeteorPlayfield* meteorPlayfield = iCreator.CreateInstance<MeteorPlayfield>("MeteorPlayfield");

	meteorPlayfield->LazyConstruct();

	return meteorPlayfield;
}

EventProcessor* MeteorRulesetExecutor::getEventProcessor(T * e)
{
	string processorType = GetProcessorType(e->GetTypeName());

	InstanceCreator<MtoObject> iCreator = InstanceCreator<MtoObject>::GetInstance();
	EventProcessor* eventProcessor = iCreator.CreateInstance<EventProcessor>(processorType);

	// 這邊要把Map Algo加進去?



	return eventProcessor;
}
