#ifndef RULESET_H
#define RULESET_H


#include"ruleset_info.h"




namespace base {
namespace ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	class ruleset_t
	{

	public:

		ruleset_t(ruleset_info_t* r);

		virtual ruleset_executor_t* create_ruleset_executor(working_sm_t* sm) = 0;

	protected:

		ruleset_info_t* ruleset_info;

	};



	

}}



#endif