#include "ExplodeMapAlgorithm.h"


using namespace Meteor::Schedulers::Events::Effects::Algorithms;


ExplodeMapAlgorithm::ExplodeMapAlgorithm(): RegisterType("ExplodeMapAlgorithm"), MapAlgorithm()
{
	genAlgo = new ExplodeMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<ExplodeEffect>();
	constructed = false;
}

int ExplodeMapAlgorithm::LazyConstruct(int w, int h)
{
	MapAlgorithm<ExplodeEffect>::LazyConstruct(w, h);
	constructed = true;
	return 0;
}

ExplodeMapAlgorithm::ExplodeMapAlgorithm(int w, int h): RegisterType("ExplodeMapAlgorithm"), MapAlgorithm(w, h)
{
	genAlgo = new ExplodeMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<ExplodeEffect>();
	constructed = true;
}

int ExplodeMapGenerateAlgorithm::Generate(Map * m, EffectMapper<ExplodeEffect>* em)
{
	MTO_FLOAT currentTime = em->GetCurrentTime();
	MTO_FLOAT lifeTime = em->GetLifeTime();
	MTO_FLOAT speed = em->GetSpeed();

	// TODO: §ï¤Ñ¦A¼g

	return 0;
}
