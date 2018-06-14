#ifndef MAP_ALGORITHM_H
#define MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"

using namespace Base::Graphic::Maps;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	template<typename T>
	class MapAlgorithm
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		MapAlgorithm(int w, int h);

		~MapAlgorithm();

		int RegisterGenerator(MapGenerateAlgorithm<T>* g);

		int RegisterShifter(MapShiftAlgorithm<T>* s);


		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		virtual int Draw(Map* m, EffectMapper<T>* em);

	protected:

		int width;

		int height;

		static Matrix2D<int>* matrix;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		MapGenerateAlgorithm<T>* genAlgo;

		/// <summary>
		/// ��ͦn��effect����L���\����m�W
		/// </summary>
		MapShiftAlgorithm<T>* shiftAlgo;

	};

	template<typename T>
	MapAlgorithm::mat = 0;

	

}}}}}








#endif