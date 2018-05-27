#ifndef RULESET_INFO_H
#define RULESET_INFO_H


#include<string>


using namespace std;


namespace Base {
namespace ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	class ruleset_info_t
	{

		int id;

		string name;

		string instantiate_name;

	public:

		ruleset_info_t(int i, string n, string instantiate_n);

		int get_id();

		int get_name();

		int get_instantiate_name();

	};



	

}}



#endif