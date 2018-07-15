#ifndef RULESET_EXECUTOR_H
#define RULESET_EXECUTOR_H


#include "RulesetInfo.h"
#include "../../Util/TemplateConstraint.h"
#include "../Scheduler/Event/Event.h"
#include "../Scheduler/Event/EventProcessor.h"
#include "../../Util/Update/Updatable.h"
#include "../Sheetmusic/SheetmusicConverter.h"
#include "../Sheetmusic/SheetmusicPostprocessor.h"
#include "../Play/Playfield.h"
#include "../Sheetmusic/Pattern/PatternGenerator.h"
#include "../Config/FrameworkConfigManager.h"
#include "../Scheduler/Event/Effect/Algorithm/MapAlgorithm.h"
#include "../Sheetmusic/WorkingSheetmusic.h"
#include "../../Util/MtoObject.h"



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
using namespace Base::Schedulers::Events::Effects::Algorithms;
using namespace Base::Rulesets;


namespace Base {
namespace Rulesets {
	
	/// <summary>
	/// a game rule that designs how the game plays
	///	</summary>
	template<class T>
	class RulesetExecutor: private TConstraint<T, Event>, public Updatable, public ChildAddable
	{

		/// <summary>
		/// jobs:
		/// 1. find the objects in sm?
		/// 2. add them to playfield?
		/// </summary>
		int playfieldLoad() {

			// 把Event轉成Event processor擺進去playfield裡
			for (int i = 0; i < sm->events->size(); i++) {

				EventProcessor<Event>* ep = getEventProcessor(sm->events->at(i));

				playfield->Add(ep);

			}

			return 0;
		}

		/// <summary>
		/// jobs:
		/// 1. create playfield
		/// 2. add playfield as child
		/// 3. ??? load objects?
		/// </summary>
		int load() {
			FrameworkConfigManager * f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
			if (!f)
				throw runtime_error("int  RulesetExecutor<T>::load() : FrameworkConfigManager not found in cache.");

			return load(f);
		}

		/// <summary>
		/// load入遊戲狀態
		/// </summary>
		int load(FrameworkConfigManager* m) {
			// 取pattern generator的名字
			string pgName;

			if (!f->Get<string>(FrameworkSetting::PatternGenerator, &pgName))
				throw runtime_error("int RulesetExecutor<T>::load(FrameworkConfigManager*) : PatternGenerator not found in Setting.");

			// 利用pattern generator的名字建立pattern generator
			InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();
			PatternGenerator* pg = iCreator.CreateInstanceWithT<PatternGenerator>(pgName);

			// 要把converter和postprocessor擺到load()裡，因為pattern Generator是擺在cache裡的
			SmConverter* converter = createSmConverter(pg);
			SmPostprocessor* postprocessor = createSmPostprocessor();

			sm = converter->Convert(workingSm->GetSm());
			sm = postprocessor->postprocess(sm);

			delete converter;
			delete postprocessor;

			// Add mods, should always be the last thing applied to give full control to mods
			// applyMods(mods);

			playfield = createPlayfield();

			// 這邊會把map algo讀進去playfield裡面，這件事要記得寫
			AddChild(playfield);

			// 把Event轉成Event processor擺進去playfield裡
			playfieldLoad();

			return 0;
		}

		//int applyMods(vector<mod*>* m);

		virtual SmConverter* createSmConverter(PatternGenerator* pg) = 0;

		virtual SmPostprocessor* createSmPostprocessor() = 0;

	public:

		/// <summary>
		/// jobs:
		/// 1. create sm from working sm
		/// 2. apply mods
		/// 3. register privateLoad()
		/// </summary>
		RulesetExecutor(): RegisterType("RulesetExecutor") {
			// 註冊private load (c++才需要)
			registerLoad(bind(static_cast<int(RulesetExecutor<T>::*)(void)>(&RulesetExecutor<T>::load), this));
		}

		int LazyConstruct(WorkingSm* w) {
			workingSm = w;

			//mods = w->get_mods();

			return 0;
		}


	protected:

		Sm<T>* sm;

		WorkingSm* workingSm;

		//vector<mod_t*> mods;

		Playfield* playfield;

		

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