#ifndef RULESET_INFO_H
#define RULESET_INFO_H


#include<string>


using namespace std;


namespace Base {
namespace Ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	class RulesetInfo
	{

		int id;

		string name;

		string instantiate_name;

	public:

		RulesetInfo(int i, string n, string instantiate_n);

		Ruleset* CreateRuleset();

		int get_id();

		int get_name();

		int get_instantiate_name();

	};



	

}}



#endif