#ifndef MAP_GENERATE_ALGORITHM_H
#define MAP_GENERATE_ALGORITHM_H

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
	class MapGenerateAlgorithm
	{

	public:
		/// <summary>
		/// 把evnet的狀態轉成圖案
		///	</summary>
		virtual int Generate(Map* m, EffectMapper<T>* em) = 0;

	};
	

}}}}}








#endif