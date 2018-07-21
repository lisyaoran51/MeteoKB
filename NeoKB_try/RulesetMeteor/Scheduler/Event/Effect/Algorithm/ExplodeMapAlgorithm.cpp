#include "ExplodeMapAlgorithm.h"


using namespace Meteor::Schedulers::Events::Effects::Algorithms;


ExplodeMapAlgorithm::ExplodeMapAlgorithm(): RegisterType("ExplodeMapAlgorithm"), MapAlgorithm()
{
	constructed = false;
}

int ExplodeMapAlgorithm::LazyConstruct(int w, int h, int sX)
{
	genAlgo = new ExplodeMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<ExplodeEffect>(sX);
	MapAlgorithm<ExplodeEffect>::LazyConstruct(w, h, sX);
	constructed = true;
	return 0;
}

ExplodeMapAlgorithm::ExplodeMapAlgorithm(int w, int h, int sX): RegisterType("ExplodeMapAlgorithm"), MapAlgorithm(w, h, sX)
{
	genAlgo = new ExplodeMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<ExplodeEffect>(sX);
	constructed = true;
}

int ExplodeMapGenerateAlgorithm::ImplementGenerate(Map * m, EffectMapper<ExplodeEffect>* em)
{

	LOG(LogLevel::Finest) << "ExplodeMapGenerateAlgorithm::ImplementGenerate() : Generate Effect [" << em->GetStartTime() << "] on [" << em->GetCurrentTime() << "].";

	MTO_FLOAT currentTime = em->GetCurrentTime();
	MTO_FLOAT lifeTime = em->GetLifeTime();
	MTO_FLOAT speed = em->GetSpeed();

	// TODO: §ï¤Ñ¦A¼g

	return 0;
}
