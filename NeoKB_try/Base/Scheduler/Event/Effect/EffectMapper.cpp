#include "EffectMapper.h"

using namespace Base::Scheduler::Event::effect;


template<class T>
EffectMapper<T>::EffectMapper(int w, int h): EventProcessor<Effect>(w,h)
{

}

template<class T>
int EffectMapper<T>::RegisterMap(Map * m)
{
	map = m;

	return 0;
}

template<class T>
int EffectMapper<T>::RegisterMapAlgo(MapAlgorithm<T>* ma)
{
	mapAlgo = ma;

	return 0;
}

template<class T>
int EffectMapper<T>::RegisterShiftAlgo(ShiftAlgorithm * sa)
{
	shiftAlgo = sa;
	return 0;
}

template<class T>
int EffectMapper<T>::Process() {

	Map* tempMap = mapAlgo(event);

	shiftAlgo(map, tempMap);

	delete tempMap;

	return 0;
}