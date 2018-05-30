#include"MeteorRuleset.h"

using namespace Meteor::Ruleset;

RulesetExecutor<Event>* MeteorRuleset::CreateRulesetExecutor(WorkingSm * sm)
{
	InstanceCreator<MtoObject> iCreator = InstanceCreator<MtoObject>::GetInstance();

	RulesetExecutor<Event>* rulesetExecutor = iCreator.CreateInstance<MeteorRulesetExecutor>("MeteorRulesetExecutor");

	// �]��instance creator�S��k�b�إߪ��ɭԴN��Ѽƥ�i�h? 
	// �S��k�@�}�l��A�ҥH�N����A��lazy construct �A�o�ˤ���w��
	rulesetExecutor->LazyConstruct(sm);

	return rulesetExecutor;
}
