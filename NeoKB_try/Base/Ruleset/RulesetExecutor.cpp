#include "RulesetExecutor.h"
#include "../../Util/MtoObject.h"


using namespace Base::Rulesets;
using namespace Util;
using namespace Base::Sheetmusics;
using namespace Base::Sheetmusics::Patterns;


template<class T>
int RulesetExecutor<T>::playfieldLoad()
{
	
	// ��Event�নEvent processor�\�i�hplayfield��
	for (int i = 0; i < sm->events->size(); i++) {
		
		EventProcessor* ep = getEventProcessor(sm->events->at(i));

		playfield->Add(ep);

	}

	return 0;
}

/// <summary>
/// load�J�C�����A
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
	// ��pattern generator���W�r
	string pgName = f->Get<string>(FrameworkSetting::PatternGenerator);

	// �Q��pattern generator���W�r�إ�pattern generator
	InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();
	PatternGenerator* pg = iCreator.CreateInstanceWithT<PatternGenerator>(pgName);

	// �n��converter�Mpostprocessor�\��load()�̡A�]��pattern Generator�O�\�bcache�̪�
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

	// ��C��event processor�|�Ψ쪺algo��Ū�X��
	mapAlgorithmLoad();

	// ��Event�নEvent processor�\�i�hplayfield��
	playfieldLoad();

	return 0;
}


template<class T>
RulesetExecutor<T>::RulesetExecutor(WorkingSm<T>* w)
{
	workingSm = w;

	mods = w->get_mods();

	// ���Uprivate load (c++�~�ݭn)
	registerLoad(bind(&RulesetExecutor<T>::load, this));
}



