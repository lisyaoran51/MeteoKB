#include "EffectMapper.h"
#include <stdexcept>

using namespace Base::Schedulers::Events::Effects;


template<class T>
EffectMapper<T>::EffectMapper(int w, int h): EffectMapperInterface(w, h)
{
	width = w;
	height = h;
	// 把effect的功能打開，擺在effect
	&effect = (T**)&event;
}

template<class T>
int EffectMapper<T>::Elapse(MTO_FLOAT elapsedTime)
{

	if (!lightMap)
		throw runtime_error("int EffectMapper::Process() : no map registered!");

	if (!mapAlgo)
		throw runtime_error("int EffectMapper::Process() : no map algorithm registered!");

	// current time從effect開始播放時，從0開始計算，直到current time超過life time時，特效結束
	currentTime += elapsedTime;

	mapAlgo->Draw(lightMap, this);

	return 0;
}

template<class T>
int EffectMapper<T>::RegisterMap(Map * m)
{
	lightMap = m;

	return 0;
}

template<class T>
int EffectMapper<T>::RegisterMapAlgorithm(MapAlgorithmInterface* ma)
{
	if (MtoObject::CanCast<MapAlgorithm<T>>(ma)) {
		mapAlgo = MtoObject::Cast<MapAlgorithm<T>>(ma);
		return 0;
	}
	else {
		// TODO: 怎麼噴錯誤?
		return -1;
	}
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

/*
// ?????
template<class T>
int EffectMapper<T>::Process() {

	if (!map)
		throw runtime_error("int EffectMapper::Process() : no map registered!");

	if (!mapAlgo)
		throw runtime_error("int EffectMapper::Process() : no map algorithm registered!");

	mapAlgo->Draw(map, this);

	return 0;
}
*/

EffectMapperInterface::EffectMapperInterface(int w, int h): EventProcessor<Event>()
{
}
