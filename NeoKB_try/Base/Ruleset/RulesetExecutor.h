#ifndef RULESET_EXECUTOR_H
#define RULESET_EXECUTOR_H


#include"RulesetInfo.h"
#include"../../Util/TemplateConstraint.h"
#include"../Scheduler/Event/Event.h"
#include"../Scheduler/Event/EventProcessor.h"
#include "../../Util/Update/updatable.h"
#include "../Sheetmusic/SheetmusicConverter.h"
#include "../Sheetmusic/SheetmusicPostprocesser.h"
#include "../Play/Playfield.h"
#include "../Sheetmusic/Pattern/PatternGenerator.h"
#include "../Config/FrameworkConfigManager.h"



/*
 * virutal private的好處，可以讓子類去修改父類，但又不能值接call父類
 * https://stackoverflow.com/questions/2170688/private-virtual-method-in-c
 */



using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;
using namespace Util::Hierachal;
using namespace Base::Play;
using namespace Base::Sheetmusics;
using namespace Base::Sheetmusics::Patterns;
using namespace Base::Config;

namespace Base {
namespace Rulesets {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	template<class T>
	class RulesetExecutor: private TConstraint<T, Event>, public Updatable, public ChildAddable
	{
		/// <summary>
		/// 把每個event processor會用到的algo先讀出來
		/// </summary>
		virtual int mapAlgorithmLoad() = 0;

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
		int load(FrameworkConfigManager* m);

		int applyMods(vector<mod*>* m);

		virtual SmConverter* createSmConverter(PatternGenerator* pg) = 0;

		virtual SmPostprocessor* createSmPostprocessor() = 0;

	public:

		/// <summary>
		/// jobs:
		/// 1. create sm from working sm
		/// 2. apply mods
		/// 3. register privateLoad()
		/// </summary>
		RulesetExecutor();

		int LazyConstruct(WorkingSm<T>* w);


	protected:

		Sm<T>* sm;

		WorkingSm<T>* workingSm;

		vector<mod_t*> mods;

		Playfield* playfield;

		///<summary>
		/// 在這邊存了會用到的algo，在getEventProcessor時可以到這邊選擇要用的algo
		///</summary>
		map<string, MapAlgorithm*> mapAlgorithms;

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*Scheduler* Scheduler;*/

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*EventProcessorMaster* EventProcessorMaster;*/

		// 移到playfield裡，因為這個是基本功能，不會隨規則變動
		/*renderer_t* renderer;*/

		vector<void*> on_judgement;

		virtual Playfield* createPlayfield() = 0;

		/// <summary>
		/// jobs:
		/// 1. 建立與event對應的processor
		/// 2. 如果processor是effect mapper，就把map algo加進去
		/// </summary>
		virtual EventProcessor<T>* getEventProcessor(T* e) = 0;
	};


	

}
}



#endif