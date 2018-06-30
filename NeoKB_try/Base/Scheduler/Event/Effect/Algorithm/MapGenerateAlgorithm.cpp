#include "MapGenerateAlgorithm.h"



using namespace Base::Schedulers::Events::Effects::Algorithms;

template<typename T>
int MapGenerateAlgorithm<T>::Generate(Map * m, EventProcessor<Event>* em)
{
	if (em->CanCast<EffectMapper<T>>()) {
		return ImplementGenerate(bufferMap, map, em->Cast<EffectMapper<T>>());
	}
	// TODO: throw error or not?
	return -1;
}