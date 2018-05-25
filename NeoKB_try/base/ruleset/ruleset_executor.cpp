#include "ruleset_executor.h"


using namespace base::ruleset;

template<class T>
int ruleset_executor_t<T>::setPlayfield()
{

	renderer = createRenderer();

	// 把event轉成event processor擺進去playfield裡


	return 0;
}

/// <summary>
/// load入遊戲狀態
/// </summary>
/// <param name="argc">輸入數目=0</param>
/// <param name="argv">無</param>
template<class T>
int ruleset_executor_t<T>::privateLoad(int argc, char ** argv)
{
	playfield = create_playfield();

	AddChild(playfield);

	setPlayfield();

	return 0;
}

template<class T>
ruleset_executor_t<T>::ruleset_executor_t(working_sm_t<T>* w)
{
	working_sm = w;

	mods = w->get_mods();

	sm_converter_t* converter = create_sm_converter();
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
	registerPrivateLoader("ruleset_executor_t", privateLoad, argc, argv);
}



