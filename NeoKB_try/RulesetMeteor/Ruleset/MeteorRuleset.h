#ifndef METEOR_RULESET_H
#define METEOR_RULESET_H

#include "../../Base/Ruleset/Ruleset.h"

using namespace Base::Rulesets;

namespace Meteor {
namespace Rulesets{

	class MeteorRuleset: public Ruleset{

	public:

		RulesetExecutor<Event>* CreateRulesetExecutor(WorkingSm* sm);

	};

}
}








#endif