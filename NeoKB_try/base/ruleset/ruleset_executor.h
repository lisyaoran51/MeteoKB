#ifndef RULESET_EXECUTOR_H
#define RULESET_EXECUTOR_H


#include"ruleset_info.h"
#include"../../Util/template_constraint.h"
#include"../scheduler/event/event.h"
#include "../../Util/Hierachal/updatable.h"
#include "../sheetmusic/sheetmusic_converter.h"
#include "../sheetmusic/sheetmusic_postprocesser.h"

/*
 * virutal private的好處，可以讓子類去修改父類，但又不能值接call父類
 * https://stackoverflow.com/questions/2170688/private-virtual-method-in-c
 */



using namespace std;
using namespace Util;
using namespace base::scheduler::event;
using namespace Util::Hierachal;

namespace base {
namespace ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	template<class T>
	class ruleset_executor_t: private T_constraint_t<T, event_t>, Updatable
	{


		/// <summary>
		/// jobs:
		/// 1. find the objects in sm?
		/// 2. add them to playfield?
		/// </summary>
		int setPlayfield();

		/// <summary>
		/// jobs:
		/// 1. create playfield
		/// 2. add playfield as child
		/// 3. ??? load objects?
		/// </summary>
		int privateLoad(int argc, char** argv);

		int apply_mods(vector<mod*>* m);

		virtual sm_converter_t* create_sm_converter();

		virtual sm_postprocessor_t* create_sm_postprocessor();

		virtual Renderer* createRenderer();

	public:

		/// <summary>
		/// jobs:
		/// 1. create sm from working sm
		/// 2. apply mods
		/// 3. register privateLoad()
		/// </summary>
		ruleset_executor_t(working_sm_t<T>* w);

	protected:

		sm_t<T>* sm;

		working_sm_t<T>* working_sm;

		vector<mod_t*> mods;

		Playfield* playfield;

		//?
		event_builder_t* event_builder;

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*scheduler_t* scheduler;*/

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*event_processor_master_t* event_processor_master;*/

		renderer_t* renderer;

		vector<void*> on_judgement;

		virtual Playfield* create_playfield() = 0;


	};



	

}
}



#endif