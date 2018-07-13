#include "MapShiftAlgorithm.h"


using namespace Base::Schedulers::Events::Effects::Algorithms;



template<typename T>
int MapShiftAlgorithm<T>::ImplementShift(Map * bufferMap, Map * map, EffectMapper<T>* em)
{
	MTO_FLOAT x = em->GetX();
	MTO_FLOAT y = em->GetY();

	// �n�T�O�첾�H��A�쥻�Abuffer map���������}�Ʒ|���ʨ�(x,y)����m�A
	// �ҥH��buffer map�q(width-x,height-y)���a��}�l���U�ӡA�o�˥������N�|�]��(x,y)
	int offsetX = width - x;
	int offsetY = height - y;
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

template<typename T>
int MapShiftAlgorithm<T>::Shift(Map * bufferMap, Map * map, EventProcessor<Event>* em)
{
	if (em->CanCast<EffectMapper<T>>()) {
		return ImplementShift(bufferMap, map, em->Cast<EffectMapper<T>>());
	}

	// TODO: throw error or not?
	return -1;
}

