#include"MapAlgorithm.h"

using namespace Base::Schedulers::Events::Effects::Algorithms;


template<typename T>
int MapAlgorithm<T>::Draw(Map * m, EventProcessor<Event>* e)
{

	if (!mat->clear)
		mat->Clean();

	genAlgo->Generate(mat, EventProcessor<Event>* e);

	shiftAlgo->Shift(mat, map, e);

	mat->Clean();

	return 0;
}
