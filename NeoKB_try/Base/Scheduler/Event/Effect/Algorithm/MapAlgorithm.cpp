#include"MapAlgorithm.h"
#include <stdexcept>


using namespace std;
using namespace Base::Schedulers::Events::Effects::Algorithms;


template<typename T>
MapAlgorithm<T>::MapAlgorithm(): RegisterType("MapAlgorithm")
{
	constructed = false;
}

template<typename T>
int MapAlgorithm<T>::LazyConstruct(int w, int h)
{
	// if not constructed
	width = w;
	height = h;
	constructed = true;
	return 0;
}

template<typename T>
MapAlgorithm<T>::MapAlgorithm(int w, int h) : RegisterType("MapAlgorithm")
{
	width = w;
	height = h;
	constructed = true;
}

template<typename T>
MapAlgorithm<T>::~MapAlgorithm()
{
	// TODO: 應該是要計算目前有幾個map algo，如果剩0個才把matrix刪掉
}

template<typename T>
int MapAlgorithm<T>::RegisterBufferMap(Map * b)
{
	if (b->GetWidth() / 2 == width && b->GetHeight() / 2 == height)
	{
		bufferMap = b;
		return 0;
	}
	// TODO: debug log
	return -1;
}

template<typename T>
int MapAlgorithm<T>::RegisterGenerator(MapGenerateAlgorithmInterface * g)
{
	if (CanCast<MapGenerateAlgorithm<T>>(g))
		return ImplementRegisterGenerator(Cast<MapGenerateAlgorithm<T>>(g));
	// throw error
	return -1;
}

template<typename T>
int MapAlgorithm<T>::RegisterShifter(MapShiftAlgorithmInterface * s)
{
	if (CanCast<MapShiftAlgorithm<T>>(s))
		return ImplementRegisterShifter(Cast<MapShiftAlgorithm<T>>(s));
	// throw error
	return -1;
}

template<typename T>
int MapAlgorithm<T>::Draw(Map * m, EventProcessor<Event>* em)
{
	// TODO: compiler should select if compile this line or not(debug level)
	//if (CanCast<EffectMapper<T>>(em))
		return ImplementDraw(m, Cast<EffectMapper<T>>(em));
	// throw error
	// return -1;
}

template<typename T>
int MapAlgorithm<T>::ImplementRegisterGenerator(MapGenerateAlgorithm<T>* g)
{
	genAlgo = g;
	return 0;
}

template<typename T>
int MapAlgorithm<T>::ImplementRegisterShifter(MapShiftAlgorithm<T>* s)
{
	shiftAlgo = s;
	return 0;
}

template<typename T>
int MapAlgorithm<T>::ImplementDraw(Map * m, EffectMapper<T>* em)
{
	if (!bufferMap->clear)
		bufferMap->Reset();

	genAlgo->Generate(bufferMap, em);

	shiftAlgo->Shift(bufferMap, m, em);

	mat->Clean();

	return 0;
}
