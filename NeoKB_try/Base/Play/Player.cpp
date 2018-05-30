#include"Player.h"
#include<string>

using namespace std;
using namespace Base::Play;
using namespace Util::Hierachal;


int Player::load()
{

	Session* s = GetCache<Session*>("Session");

	rulesetInfo = s->GetRulesetInfo();
	workingSm = s->GetWorkingSm();

	Sm* sm = workingSm->GetSm();

	if (!rulesetInfo)
		rulesetInfo = sm->GetRulesetInfo();
	Ruleset* r = rulesetInfo->CreateRuleset();

	rulesetExecutor = r->CreateRulesetExecutor(workingSm);

	AddChild(rulesetExecutor);

	return 0;
}
