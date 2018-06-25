#include "MapShiftAlgorithm.h"


using namespace Base::Schedulers::Events::Effects::Algorithms;



template<typename T>
int MapShiftAlgorithm<T>::Shift(Map * bufferMap, Map * map, EffectMapper<T>* em)
{
	// TODO:
	MTO_FLOAT x = em->GetX();
	MTO_FLOAT y = em->GetY();

	int offsetX = width - x;
	int offsetY = width - y;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map->Add(
				i,
				j,
				bufferMap->Get(i + offsetX, j + offsetY);
			)
		}
	}
	return 0;
}


