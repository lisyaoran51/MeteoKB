#ifndef METEOR_RULESET_H
#define METEOR_RULESET_H

#include "../../Base/Ruleset/Ruleset.h"

using namespace Base::Ruleset;

namespace Meteor {
namespace Ruleset{

	class MeteorRuleset: public Ruleset{

	public:

		RulesetExecutor<Event>* CreateRulesetExecutor(WorkingSm* sm);

	};

}
}








#endif