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
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* em) = 0;
	};


	template<typename T>
	class MapAlgorithm: public MapAlgorithmInterface, public MtoObject
	{

		bool constructed;

	public:

		/// <summary>
		/// �L�\�Ϊ��غc�l�A�n�f�tlazy construct
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
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
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
		/// ��ͦn��effect����L���\����m�W
		/// </summary>
		MapShiftAlgorithm<T>* shiftAlgo;

		int ImplementRegisterGenerator(MapGenerateAlgorithm<T>* g);

		int ImplementRegisterShifter(MapShiftAlgorithm<T>* s);


		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		//virtual int Draw(Map* m, T* e);

		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		virtual int ImplementDraw(Map* m, EffectMapper<T>* em);

	};

	

}}}}}








#endif