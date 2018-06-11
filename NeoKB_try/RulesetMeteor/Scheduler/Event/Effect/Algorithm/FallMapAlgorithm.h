#ifndef FALL_MAP_ALGORITHM_H
#define FALL_MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"


using namespace Base::Graphic::Maps;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class FallMapAlgorithm: public MapAlgorithm<FallEffectMapper>
	{

	public:

		/// <summary>
		/// 把evnet的狀態轉成圖案，然後移到他的位置上
		///	</summary>
		int Draw(Map* m, FallEffectMapper* e);


	};



	

}}}}}








#endif