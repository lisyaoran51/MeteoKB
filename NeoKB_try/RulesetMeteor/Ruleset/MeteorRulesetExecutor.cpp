#include "MeteorRulesetExecutor.h"

using namespace Meteor::Rulesets;
using namespace Base::Schedulers::Events;

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

	// 這邊要把Map Algo加進去
	if (eventProcessor is EffectMapper) {
		
		MapAlgoritmh* mapAlgo = mapAlgorithms[processorType];
		if (mapAlgo)
			static_cast<EffectMapper*>(eventProcessor)->RegisterMapAlgorithm(mapAlgo);

	}

	return eventProcessor;
}
