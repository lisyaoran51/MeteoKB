#include "ruleset_executor.h"


using namespace base::ruleset;

template<class T>
int ruleset_executor_t<T>::setPlayfield()
{

	renderer = createRenderer();

	// ��event�নevent processor�\�i�hplayfield��


	return 0;
}

/// <summary>
/// load�J�C�����A
/// </summary>
/// <param name="argc">��J�ƥ�=0</param>
/// <param name="argv">�L</param>
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

	// ���Uprivate load (c++�~�ݭn)
	int argc = 0;
	char** argv = NULL;
	registerPrivateLoader("ruleset_executor_t", privateLoad, argc, argv);
}



