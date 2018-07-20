#include"Player.h"
#include<string>
#include "Session.h"
#include "../Sheetmusic/Sheetmusic.h"

using namespace std;
using namespace Base::Play;
using namespace Util::Hierachal;
using namespace Base::Rulesets;
using namespace Base::Sheetmusics;


int Player::load()
{
	LOG(LogLevel::Info) << "Player::load : start loading the player and reading the sm and ruleset from session.";

	Session* s = GetCache<Session>("Session");

	rulesetInfo = s->GetRulesetInfo();
	workingSm = s->GetWorkingSm();			// workingSm要在遊戲結束以後刪掉
	

	Sm<Event>* sm = workingSm->GetSm();

	if (!rulesetInfo)
		rulesetInfo = sm->GetRulesetInfo();
	ruleset = rulesetInfo->CreateRuleset();

	rulesetExecutor = ruleset->CreateRulesetExecutor(workingSm);

	AddChild(rulesetExecutor);

	return 0;
}

Player::Player(): RegisterType("Player"), ChildAddable()
{
	registerLoad(bind((int(Player::*)())&Player::load, this));
}

Base::Play::Player::~Player()
{
	delete ruleset;
	delete rulesetExecutor;
	delete workingSm;
}
