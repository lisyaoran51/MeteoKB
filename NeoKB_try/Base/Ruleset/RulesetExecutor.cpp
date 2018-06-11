#include "RulesetExecutor.h"
#include "../../Util/MtoObject.h"


using namespace Base::Rulesets;
using namespace Util;
using namespace Base::Sheetmusics;
using namespace Base::Sheetmusics::Patterns;


template<class T>
int RulesetExecutor<T>::playfieldLoad()
{
	
	// 把Event轉成Event processor擺進去playfield裡
	for (int i = 0; i < sm->events->size(); i++) {
		
		EventProcessor* ep = getEventProcessor(sm->events->at(i));

		playfield->Add(ep);

	}

	return 0;
}

/// <summary>
/// load入遊戲狀態
/// </summary>
template<class T>
int RulesetExecutor<T>::load()
{
	MeteorConfigManager * f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");

	return load(f);
}

template<class T>
int RulesetExecutor<T>::load(FrameworkConfigManager* f)
{
	// 取pattern generator的名字
	string pgName = f->Get<string>(FrameworkSetting::PatternGenerator);

	// 利用pattern generator的名字建立pattern generator
	InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();
	PatternGenerator* pg = iCreator.CreateInstanceWithT<PatternGenerator>(pgName);

	// 要把converter和postprocessor擺到load()裡，因為pattern Generator是擺在cache裡的
	SmConverter* converter = createSmConverter(pg);
	SmPostprocessor* postprocessor = createSmPostprocessor();

	sm = converter->Convert(workingSm->get_sm());
	sm = postprocessor->postprocess(sm);

	delete converter;
	delete postprocessor;

	// Add mods, should always be the last thing applied to give full control to mods
	// applyMods(mods);

	playfield = createPlayfield();

	AddChild(playfield);

	// 把每個event processor會用到的algo先讀出來
	mapAlgorithmLoad();

	// 把Event轉成Event processor擺進去playfield裡
	playfieldLoad();

	return 0;
}


template<class T>
RulesetExecutor<T>::RulesetExecutor(WorkingSm<T>* w)
{
	workingSm = w;

	mods = w->get_mods();

	// 註冊private load (c++才需要)
	registerLoad(bind(&RulesetExecutor<T>::load, this));
}



