#include "MeteorRulesetExecutor.h"

#include "../Sheetmusic/MeteorSheetmusicConverter.h"
#include "../Play/MeteorPlayfield.h"
#include "../../Base/Scheduler/Event/Effect/EffectMapper.h"

using namespace Meteor::Rulesets;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics;
using namespace Meteor::Sheetmusics;
using namespace Meteor::Play;
using namespace Base::Schedulers::Events::Effects;



SmConverter * MeteorRulesetExecutor::createSmConverter(PatternGenerator * pg)
{
	return new MeteorSmConverter(pg);
}

SmPostprocessor * MeteorRulesetExecutor::createSmPostprocessor()
{
	return new SmPostprocessor();
}

Playfield* MeteorRulesetExecutor::createPlayfield()
{
	/* 不用搞那麼複雜，直接new一個就好
	InstanceCreator<MtoObject> iCreator = InstanceCreator<MtoObject>::GetInstance();
	MeteorPlayfield* meteorPlayfield = iCreator.CreateInstance<MeteorPlayfield>("MeteorPlayfield");

	meteorPlayfield->LazyConstruct();
	*/
	return new MeteorPlayfield();
}

EventProcessor<Event>* MeteorRulesetExecutor::getEventProcessor(Event * e)
{
	// 為什麼不用event自己來create? 因為要去搭配不同的mapper，所以要動態調配
	string processorType = GetProcessorType(e->GetTypeName());

	//InstanceCreator<MtoObject>& iCreator = InstanceCreator<MtoObject>::GetInstance();
	//EventProcessor<Event>* eventProcessor = iCreator.CreateInstance<EventProcessor<Event>>(processorType);
	switch (processorType) {
	case "FallEffectMapper":
		return new FallEffectMapper()
	}
	

	return eventProcessor;
}

