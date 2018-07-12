#include "Ruleset.h"

using namespace Base::Rulesets;



Ruleset::Ruleset(RulesetInfo * r): RegisterType("Ruleset")
{
	rulesetInfo = r;
}

Ruleset::~Ruleset()
{
}

