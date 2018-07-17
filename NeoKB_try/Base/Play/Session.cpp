#include "Session.h"

using namespace Base::Play;
using namespace Base::Sheetmusics;

/* 本來要用讀取的來讀規則和普，但是發現規則和普都不能讀(不是mto object)，所以改到建構子裡
int Session::load()
{
	RulesetInfo* r = GetCache<RulesetInfo>("RulesetInfo");

	if (!r)
		throw runtime_error("int Session::load() : RulesetInfo not found in cache.");

	SmManager* s = GetCache<SmManager>("SmManager");

	if (!s)
		throw runtime_error("int MeteorPlayfield::load() : SmManager not found in cache.");

	return load(r, s);
}

int Session::load(RulesetInfo * r, SmManager * s)
{
	rulesetInfo = r;

	smManager = s;

	smInfo = smManager->GetSmInfos()->at(0);

	return 0;
}
*/

Session::Session(RulesetInfo* r, SmManager* s): RegisterType("Session"), ChildAddable()
{
	rulesetInfo = r;

	smManager = s;

	smInfo = smManager->GetSmInfos()->at(0);

	//registerLoad(bind((int(Session::*)())&Session::load, this));
}

RulesetInfo * Session::GetRulesetInfo()
{
	return rulesetInfo;
}

WorkingSm * Session::GetWorkingSm()
{
	return smManager->GetWorkingSm(smInfo);
}
