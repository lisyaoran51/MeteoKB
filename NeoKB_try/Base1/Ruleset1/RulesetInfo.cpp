#include "RulesetInfo.h"
#include "../../Util/InstanceCreator.h"
#include "../../Util/MtoObject.h"


using namespace Base::Rulesets;
using namespace Util;


RulesetInfo::RulesetInfo(string n)
{
	name = n;
}

Ruleset* RulesetInfo::CreateRuleset()
{
	InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();
	Ruleset* r = iCreator.CreateInstanceWithT<Ruleset>(name);
	return r;
}

int RulesetInfo::GetId()
{
	return id;
}

string RulesetInfo::GetName()
{
	return name;
}
