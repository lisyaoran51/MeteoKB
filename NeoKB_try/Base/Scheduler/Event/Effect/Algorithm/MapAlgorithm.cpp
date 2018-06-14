#include"MapAlgorithm.h"
#include <stdexcept>


using namespace std;
using namespace Base::Schedulers::Events::Effects::Algorithms;


template<typename T>
MapAlgorithm<T>::MapAlgorithm(int w, int h)
{
	if (!matrix)
		matrix = new Matrix2D(2*w, 2*h);
	else if (matrix->width != 2*w || matrix->height != 2*h)
		throw invalid_argument("MapAlgorithm<T>::MapAlgorithm(int w, int h) : the width and height do not fit the existing matrix.");

}

template<typename T>
MapAlgorithm<T>::~MapAlgorithm()
{
	// TODO: 應該是要計算目前有幾個map algo，如果剩0個才把matrix刪掉
	if (matrix) {
		delete matrix;
		matrix = 0;
	}
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

	if (!matrix->clear)
		matrix->Clean();

	genAlgo->Generate(matrix, em);

	shiftAlgo->Shift(mat, map, em);

	mat->Clean();

	return 0;
}
