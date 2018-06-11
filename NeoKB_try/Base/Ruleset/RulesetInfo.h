#ifndef RULESET_INFO_H
#define RULESET_INFO_H


#include<string>
#include "Ruleset.h"


using namespace std;


namespace Base {
namespace Rulesets {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	class RulesetInfo
	{

		int id;

		string name;

		string instantiateName;

	public:

		RulesetInfo(int i, string n);

		Ruleset* CreateRuleset();

		int GetId();

		string GetName();


	};



	

}}



#endif