#ifndef RULESET_EXECUTOR_H
#define RULESET_EXECUTOR_H


#include"ruleset_info.h"
#include"../../util/template_constraint.h"
#include"../scheduler/event/event.h"


using namespace std;
using namespace util;
using namespace base::scheduler::event;


namespace base {
namespace ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	template<class T>
	class ruleset_executor_t: T_constraint_t<event_group_t>
	{

		/// <summary>
		/// make a constraint for template
		/// </summary>
		void constraint_check() {
			constraint_check_derived_from<T>();
		}

		int apply_mods(vector<mod*>* m);

	public:

		

	protected:

		sm_t<T>* sm;

		working_sm_t<T>* working_sm;

		vector<mod*> mods;

		playfield_t* playfield;

		event_builder_t* event_builder;

		scheduler_t* scheduler;

		event_processor_master_t* event_processor_master;

		renderer_t* renderer;

		/// <summary>
		/// when added to a object hierchy, do load() to load in the information in the hierachy.
		/// </summary>
		int load();

		virtual int create_playfield() = 0;


	};



	

}}



#endif