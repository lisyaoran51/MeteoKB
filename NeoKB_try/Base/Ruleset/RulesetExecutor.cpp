#include "RulesetExecutor.h"


using namespace Base::Ruleset;

template<class T>
int RulesetExecutor<T>::playfieldLoad()
{

	// 把Event轉成Event processor擺進去playfield裡
	for (int i = 0; i < sm->events->size(); i++) {
		
		EventProcessor* ep = getEventProcessor(sm->events->at(i));

		playfield->add(ep);

	}

	return 0;
}

/// <summary>
/// load入遊戲狀態
/// </summary>
template<class T>
int RulesetExecutor<T>::load()
{
	playfield = create_playfield();

	AddChild(playfield);

	// 把Event轉成Event processor擺進去playfield裡
	playfieldLoad();

	return 0;
}

template<class T>
RulesetExecutor<T>::RulesetExecutor(WorkingSm<T>* w)
{
	working_sm = w;

	mods = w->get_mods();

	SmConverter* converter = create_sm_converter();
	sm_postprocessor_t* postprocessor = create_sm_postprocessor();

	sm = converter->convert(w->get_sm());
	sm = postprocessor->postprocess(sm);

	delete converter;
	delete postprocessor;

	// Add mods, should always be the last thing applied to give full control to mods
	apply_mods(mods);

	// 註冊private load (c++才需要)
	int argc = 0;
	char** argv = NULL;
	registerPrivateLoader("RulesetExecutor", privateLoad, argc, argv);
}



