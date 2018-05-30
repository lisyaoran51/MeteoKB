#ifndef RULESET_EXECUTOR_H
#define RULESET_EXECUTOR_H


#include"ruleset_info.h"
#include"../../Util/TemplateConstraint.h"
#include"../Scheduler/Event/Event.h"
#include"../Scheduler/Event/EventProcessor.h"
#include "../../Util/Hierachal/updatable.h"
#include "../Sheetmusic/sheetmusic_converter.h"
#include "../Sheetmusic/sheetmusic_postprocesser.h"
#include "../Play/Playfield.h"


/*
 * virutal private的好處，可以讓子類去修改父類，但又不能值接call父類
 * https://stackoverflow.com/questions/2170688/private-virtual-method-in-c
 */



using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;
using namespace Util::Hierachal;
using namespace Base::Play;

namespace Base {
namespace Ruleset {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	template<class T>
	class RulesetExecutor: private TConstraint<T, Event>, Updatable
	{


		/// <summary>
		/// jobs:
		/// 1. find the objects in sm?
		/// 2. add them to playfield?
		/// </summary>
		int playfieldLoad();

		/// <summary>
		/// jobs:
		/// 1. create playfield
		/// 2. add playfield as child
		/// 3. ??? load objects?
		/// </summary>
		int load();

		int apply_mods(vector<mod*>* m);

		virtual SmConverter* create_sm_converter() = 0;

		virtual sm_postprocessor_t* create_sm_postprocessor() = 0;

	public:

		/// <summary>
		/// jobs:
		/// 1. create sm from working sm
		/// 2. apply mods
		/// 3. register privateLoad()
		/// </summary>
		RulesetExecutor(WorkingSm<T>* w);

	protected:

		Sm<T>* sm;

		WorkingSm<T>* working_sm;

		vector<mod_t*> mods;

		Playfield* playfield;

		//?
		event_builder_t* event_builder;

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*Scheduler* Scheduler;*/

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*EventProcessorMaster* EventProcessorMaster;*/

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*renderer_t* renderer;*/

		vector<void*> on_judgement;

		virtual Playfield* create_playfield() = 0;

		virtual EventProcessor* getEventProcessor(T* e) = 0;
	};



	

}
}



#endif