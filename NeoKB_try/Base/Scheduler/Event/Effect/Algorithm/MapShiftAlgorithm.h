#ifndef MAP_SHIFT_ALGORITHM_H
#define MAP_SHIFT_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../EffectMapper.h"

using namespace Base::Graphic::Maps;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	/// <summary>
	/// 畫出特效
	///	</summary>
	template<typename T>
	class MapShiftAlgorithm
	{

	public:
		/// <summary>
		/// 移動到指定位置上
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* map, EffectMapper<T>* em);

	};
	

}}}}}








#endif