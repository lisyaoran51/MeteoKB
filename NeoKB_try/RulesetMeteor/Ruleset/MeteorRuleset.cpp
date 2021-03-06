#include"MeteorRuleset.h"
#include "MeteorRulesetExecutor.h"

using namespace Meteor::Rulesets;

MeteorRuleset::MeteorRuleset() : RegisterType("Ruleset")
{
	constructed = false;
}

MeteorRuleset::MeteorRuleset(RulesetInfo * r): RegisterType("Ruleset")
{
	rulesetInfo = r;
	constructed = true;
}

int MeteorRuleset::LazyConstruct(RulesetInfo * r)
{
	Ruleset::LazyConstruct(r);
	constructed = true;
	return 0;
}

RulesetExecutor<Event>* MeteorRuleset::CreateRulesetExecutor(WorkingSm * sm)
{
	InstanceCreator<MtoObject>& iCreator = InstanceCreator<MtoObject>::GetInstance();

	RulesetExecutor<Event>* rulesetExecutor = iCreator.CreateInstanceWithT<MeteorRulesetExecutor>("MeteorRulesetExecutor");

	// 因為instance creator沒辦法在建立的時候就把參數丟進去? 
	// 沒辦法一開始丟，所以就之後再來lazy construct ，這樣比較安全
	rulesetExecutor->LazyConstruct(sm);

	return rulesetExecutor;
}
