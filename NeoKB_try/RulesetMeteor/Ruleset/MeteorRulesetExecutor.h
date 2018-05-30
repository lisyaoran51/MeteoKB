#ifndef METEOR_RULESET_EXCUTOR_H
#define METEOR_RULESET_EXCUTOR_H

#include "../../Base/Ruleset/Ruleset.h"


using namespace Base::Ruleset;
using namespace Base::Scheduler::Event;

namespace Meteor {
namespace Ruleset{

	class MeteorRulesetExecutor: public RulesetExecutor<Event>{

		map<string, string> eventProcessorTable;

	protected:

		Playfield* create_playfield();

		EventProcessor* getEventProcessor(T* e);

		string GetProcessorType(string eventType);

	};

}
}







#endif