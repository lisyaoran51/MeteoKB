#include "EffectMapper.h"
#include <stdexcept>

using namespace Base::Schedulers::Events::Effects;


template<class T>
EffectMapper<T>::EffectMapper(int w, int h): EventProcessor<Event>(w,h)
{

	&effect = (T**)&event;
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
int EffectMapper<T>::Process() {

	if (!map)
		throw runtime_error("int EffectMapper::Process() : no map registered!");

	if (!mapAlgo)
		throw runtime_error("int EffectMapper::Process() : no map algorithm registered!");

	mapAlgo->Draw(map, this);

	return 0;
}