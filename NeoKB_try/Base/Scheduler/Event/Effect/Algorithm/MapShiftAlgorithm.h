#ifndef MAP_SHIFT_ALGORITHM_H
#define MAP_SHIFT_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../../Event.h"
#include "../../EventProcessor.h"

using namespace Base::Graphic::Maps;

namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {

	template<typename T>
	class EffectMapper;

}}}}

using namespace Base::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events;

namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class MapShiftAlgorithmInterface {

	public:

		// EventProcessor<Event> = EffectMapper<T>
		// 因為template不能做多型，所以多切一層interface出來
		/// <summary>
		/// 移動到指定位置上
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* lightMap, EventProcessor<Event>* em) = 0;


	};


	/// <summary>
	/// 移動特效的位置
	///	</summary>
	template<typename T>
	class MapShiftAlgorithm: public MapShiftAlgorithmInterface
	{

	public:
		/// <summary>
		/// 移動到指定位置上
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* lightMap, EventProcessor<Event>* em);

	protected:

		/// <summary>
		/// 移動到指定位置上
		///	</summary>
		virtual int ImplementShift(Map* bufferMap, Map* lightMap, EffectMapper<T>* em);

	};
	

}}}}}








#endif