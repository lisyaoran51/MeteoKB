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
		MapAlgorithm(): RegisterType("MapAlgorithm") {
			constructed = false;
		}

		int LazyConstruct(int w, int h) {
			// if not constructed
			width = w;
			height = h;
			constructed = true;
			return 0;
		}

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		MapAlgorithm(int w, int h) : RegisterType("MapAlgorithm")
		{
			width = w;
			height = h;
			constructed = true;
		}

		~MapAlgorithm() {
			// TODO: 應該是要計算目前有幾個map algo，如果剩0個才把matrix刪掉
		}

		virtual int RegisterBufferMap(Map* b) {
			if (b->GetWidth() / 2 == width && b->GetHeight() / 2 == height)
			{
				bufferMap = b;
				return 0;
			}
			// TODO: debug Log
			return -1;
		}

		virtual int RegisterGenerator(MapGenerateAlgorithmInterface* g) {
			if (CanCast<MapGenerateAlgorithm<T>>(g))
				return ImplementRegisterGenerator(Cast<MapGenerateAlgorithm<T>>(g));
			// throw error
			return -1;
		}

		virtual int RegisterShifter(MapShiftAlgorithmInterface* s) {
			if (CanCast<MapShiftAlgorithm<T>>(s))
				return ImplementRegisterShifter(Cast<MapShiftAlgorithm<T>>(s));
			// throw error
			return -1;
		}


		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* em) {
			// TODO: compiler should select if compile this line or not(debug level)
			//if (CanCast<EffectMapper<T>>(em))
			return ImplementDraw(m, Cast<EffectMapper<T>>(em));
			// throw error
			// return -1;
		}

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

		int ImplementRegisterGenerator(MapGenerateAlgorithm<T>* g) {
			genAlgo = g;
			return 0;
		}

		int ImplementRegisterShifter(MapShiftAlgorithm<T>* s) {
			shiftAlgo = s;
			return 0;
		}


		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		virtual int ImplementDraw(Map* m, EffectMapper<T>* em) {
			if (!bufferMap->IsClear())
				bufferMap->Reset();

			genAlgo->Generate(bufferMap, em);

			shiftAlgo->Shift(bufferMap, m, em);

			bufferMap->Reset();

			return 0;
		}

	};

	

}}}}}








#endif