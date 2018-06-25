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
int MapAlgorithm<T>::RegisterGenerator(MapGenerateAlgorithm<T>* g)
{
	genAlgo = g;
	return 0;
}

template<typename T>
int MapAlgorithm<T>::RegisterShifter(MapShiftAlgorithm<T>* s)
{
	shiftAlgo = s;
	return 0;
}

template<typename T>
int MapAlgorithm<T>::Draw(Map * m, EffectMapper<T>* em)
{

	if (!bufferMap->clear)
		bufferMap->Clean();

	genAlgo->Generate(bufferMap, em);

	shiftAlgo->Shift(bufferMap, map, em);

	mat->Clean();

	return 0;
}
