#include "MeteorRulesetExecutor.h"
#include "../Sheetmusic/MeteorSheetmusicConverter.h"

using namespace Meteor::Rulesets;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics;
using namespace Meteor::Sheetmusics;

SmConverter * MeteorRulesetExecutor::createSmConverter(PatternGenerator * pg)
{
	return new MeteorSmConverter(pg);
}

Playfield* MeteorRulesetExecutor::create_playfield()
{

	InstanceCreator<MtoObject> iCreator = InstanceCreator<MtoObject>::GetInstance();
	MeteorPlayfield* meteorPlayfield = iCreator.CreateInstance<MeteorPlayfield>("MeteorPlayfield");

	meteorPlayfield->LazyConstruct();

	return meteorPlayfield;
}

EventProcessor<Event>* Meteor::Rulesets::MeteorRulesetExecutor::getEventProcessor(Event * e)
{
	return nullptr;
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
