#include "GlowLineMapAlgorithm.h"

using namespace Meteor::Schedulers::Events::Effects::Algorithms;

GlowLineMapAlgorithm::GlowLineMapAlgorithm(): RegisterType("GlowLineMapAlgorithm"), MapAlgorithm()
{
	constructed = false;
}

int GlowLineMapAlgorithm::LazyConstruct(int w, int h, int sX)
{
	MapAlgorithm<GlowLineEffect>::LazyConstruct(w, h, sX);
	genAlgo = new GlowLineMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<GlowLineEffect>(sX);
	constructed = true;
	return 0;
}

GlowLineMapAlgorithm::GlowLineMapAlgorithm(int w, int h, int sX) : RegisterType("GlowLineMapAlgorithm"), MapAlgorithm(w, h, sX)
{
	genAlgo = new GlowLineMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<GlowLineEffect>(sX);
	constructed = true;
}

int GlowLineMapGenerateAlgorithm::ImplementGenerate(Map * m, EffectMapper<GlowLineEffect>* em)
{

	LOG(LogLevel::Finest) << "GlowLineMapGenerateAlgorithm::ImplementGenerate() : Generate Effect [" << em->GetStartTime() << "] on [" << em->GetCurrentTime() << "].";

	// TODO: Ãi±o¼g ¤U¦¸¼g
	return 0;
}
