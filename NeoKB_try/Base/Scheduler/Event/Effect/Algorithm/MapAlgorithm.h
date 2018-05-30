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

		int RegisterGenerator(GenerateAlgorithm* g);

		int RegisterShifter(ShiftAlgorithm* s);


		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* e);

	protected:

		Matrix2D<int>* mat;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		GenerateAlgorithm* genAlgo;

		/// <summary>
		/// 把生好的effect移到他該擺的位置上
		/// </summary>
		ShiftAlgorithm* shiftAlgo;

	};



	

}}}}}








#endif