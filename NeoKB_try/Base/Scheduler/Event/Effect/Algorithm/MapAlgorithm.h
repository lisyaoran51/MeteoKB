#ifndef MAP_ALGORITHM_H
#define MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../../../../../Util/MtoObject.h"
#include "MapGenerateAlgorithm.h"
#include "MapShiftAlgorithm.h"


using namespace Base::Graphic::Maps;
using namespace Util;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {

	template<typename T>
	class EffectMapper;

}}}}

using namespace Base::Schedulers::Events::Effects;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	

	class MapAlgorithmInterface {

	public:

		virtual int RegisterBufferMap(Map* b) = 0;

		virtual int RegisterGenerator(MapGenerateAlgorithmInterface* g) = 0;

		virtual int RegisterShifter(MapShiftAlgorithmInterface* s) = 0;

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* em) = 0;
	};


	template<typename T>
	class MapAlgorithm: public MapAlgorithmInterface, public MtoObject
	{

		bool constructed;

	public:

		/// <summary>
		/// 無功用的建構子，要搭配lazy construct
		///	</summary>
		MapAlgorithm();

		int LazyConstruct(int w, int h);

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		MapAlgorithm(int w, int h);

		~MapAlgorithm();

		virtual int RegisterBufferMap(Map* b);

		virtual int RegisterGenerator(MapGenerateAlgorithmInterface* g);

		virtual int RegisterShifter(MapShiftAlgorithmInterface* s);


		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* em);

	protected:

		int width;

		int height;

		//static Matrix2D<int>* matrix;

		Map* bufferMap;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		MapGenerateAlgorithm<T>* genAlgo;

		/// <summary>
		/// 把生好的effect移到他該擺的位置上
		/// </summary>
		MapShiftAlgorithm<T>* shiftAlgo;

		int ImplementRegisterGenerator(MapGenerateAlgorithm<T>* g);

		int ImplementRegisterShifter(MapShiftAlgorithm<T>* s);


		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int ImplementDraw(Map* m, EffectMapper<T>* em);

	};

	

}}}}}








#endif