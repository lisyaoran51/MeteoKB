#ifndef RULESET_H
#define RULESET_H


#include"RulesetInfo.h"
#include"RulesetExecutor.h"



namespace Base {
namespace Ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	class Ruleset
	{

	public:

		Ruleset(RulesetInfo* r);

		virtual RulesetExecutor<Event>* CreateRulesetExecutor(WorkingSm* sm) = 0;

	protected:

		RulesetInfo* rulesetInfo;

	};

}}



#endif