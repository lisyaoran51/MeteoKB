#include "RulesetExecutor.h"


using namespace Base::ruleset;

template<class T>
int RulesetExecutor<T>::loadEventToPlayfield()
{

	// ��Event�নEvent processor�\�i�hplayfield��
	for (int i = 0; i < sm->events->size(); i++) {
		
		EventProcessor* ep = getEventProcessor(sm->events->at(i));

		playfield->add(ep);

	}

	return 0;
}

/// <summary>
/// load�J�C�����A
/// </summary>
/// <param name="argc">��J�ƥ�=0</param>
/// <param name="argv">�L</param>
template<class T>
int RulesetExecutor<T>::privateLoad(int argc, char ** argv)
{
	playfield = create_playfield();

	AddChild(playfield);

	// ��Event�নEvent processor�\�i�hplayfield��
	playfieldLoad();

	return 0;
}

template<class T>
RulesetExecutor<T>::RulesetExecutor(working_sm_t<T>* w)
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
	registerPrivateLoader("RulesetExecutor", privateLoad, argc, argv);
}



