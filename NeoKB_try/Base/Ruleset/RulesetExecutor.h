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
 * virutal private���n�B�A�i�H���l���h�ק�����A���S����ȱ�call����
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
		/// ��C��event processor�|�Ψ쪺algo��Ū�X��
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
		/// �b�o��s�F�|�Ψ쪺algo�A�bgetEventProcessor�ɥi�H��o���ܭn�Ϊ�algo
		///</summary>
		map<string, MapAlgorithm*> mapAlgorithms;

		// ����playfield�̡A�]���o�ӬO�򥻥\��A���|�H�W�h�ܰ�
		/*Scheduler* Scheduler;*/

		// ����playfield�̡A�]���o�ӬO�򥻥\��A���|�H�W�h�ܰ�
		/*EventProcessorMaster* EventProcessorMaster;*/

		// ����playfield�̡A�]���o�ӬO�򥻥\��A���|�H�W�h�ܰ�
		/*renderer_t* renderer;*/

		vector<void*> on_judgement;

		virtual Playfield* createPlayfield() = 0;

		/// <summary>
		/// jobs:
		/// 1. �إ߻Pevent������processor
		/// 2. �p�Gprocessor�Oeffect mapper�A�N��map algo�[�i�h
		/// </summary>
		virtual EventProcessor<T>* getEventProcessor(T* e) = 0;
	};


	

}
}



#endif