#include "MapShiftAlgorithm.h"


using namespace Base::Schedulers::Events::Effects::Algorithms;



template<typename T>
int MapShiftAlgorithm<T>::ImplementShift(Map * bufferMap, Map * lightMap, EffectMapper<T>* em)
{
	MTO_FLOAT x = em->GetX();
	MTO_FLOAT y = em->GetY();

	MTO_FLOAT width = lightMap->GetWidth();
	MTO_FLOAT height = lightMap->GetHeight();


	// 要確保位移以後，原本再buffer map正中央的洞化會移動到(x,y)的位置，
	// 所以把buffer map從(width-x,height-y)的地方開始切下來，這樣正中央就會跑到(x,y)
	int offsetX = width - x;
	int offsetY = height - y;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			lightMap->Add(
				i,
				j,
				bufferMap->Get(i + offsetX, j + offsetY)
			);
		}
	}
	return 0;
}

template<typename T>
int MapShiftAlgorithm<T>::Shift(Map * bufferMap, Map * lightMap, EventProcessor<Event>* em)
{
	if (em->CanCast<EffectMapper<T>>()) {
		return ImplementShift(bufferMap, lightMap, em->Cast<EffectMapper<T>>());
	}

	// TODO: throw error or not?
	return -1;
}


