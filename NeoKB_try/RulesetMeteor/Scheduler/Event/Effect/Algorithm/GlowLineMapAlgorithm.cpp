#include "GlowLineMapAlgorithm.h"

using namespace Meteor::Schedulers::Events::Effects::Algorithms;

GlowLineMapAlgorithm::GlowLineMapAlgorithm(): RegisterType("GlowLineMapAlgorithm"), MapAlgorithm()
{
	genAlgo = new GlowLineMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<GlowLineEffect>();
	constructed = false;
}

int GlowLineMapAlgorithm::LazyConstruct(int w, int h)
{
	MapAlgorithm<GlowLineEffect>::LazyConstruct(w, h);
	constructed = true;
	return 0;
}

GlowLineMapAlgorithm::GlowLineMapAlgorithm(int w, int h) : RegisterType("GlowLineMapAlgorithm"), MapAlgorithm(w, h)
{
	genAlgo = new GlowLineMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<GlowLineEffect>();
	constructed = true;
}

int GlowLineMapGenerateAlgorithm::ImplementGenerate(Map * m, EffectMapper<GlowLineEffect>* em)
{

	LOG(LogLevel::Finest) << "GlowLineMapGenerateAlgorithm::ImplementGenerate() : Generate Effect [" << em->GetStartTime() << "] on [" << em->GetCurrentTime() << "].";

	// TODO: Ãi±o¼g ¤U¦¸¼g
	return 0;
}
