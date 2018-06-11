#include "RulesetInfo.h"


using namespace Base::Rulesets;


RulesetInfo::RulesetInfo(int i, string n)
{
	id = i;
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
