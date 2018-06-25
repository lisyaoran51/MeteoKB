#include "EffectMapper.h"
#include <stdexcept>

using namespace Base::Schedulers::Events::Effects;


template<class T>
EffectMapper<T>::EffectMapper(int w, int h): EventProcessor<Event>()
{
	width = w;
	hieght = h;
	// 把effect的功能打開，擺在effect
	&effect = (T**)&event;
}

template<class T>
int EffectMapper<T>::RegisterMap(Map * m)
{
	map = m;

	return 0;
}

template<class T>
int EffectMapper<T>::RegisterMapAlgorithm(MapAlgorithm<T>* ma)
{
	mapAlgo = ma;

	return 0;
}

template<class T>
int EffectMapper<T>::GetWidth()
{
	return width;
}

template<class T>
int EffectMapper<T>::GetHeight()
{
	return height;
}

template<class T>
int EffectMapper<T>::GetX()
{
	return effect->GetX();
}

template<class T>
int EffectMapper<T>::GetY()
{
	return effect->GetY();
}

template<class T>
MTO_FLOAT EffectMapper<T>::GetSpeed()
{
	return effect->GetSpeed();
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