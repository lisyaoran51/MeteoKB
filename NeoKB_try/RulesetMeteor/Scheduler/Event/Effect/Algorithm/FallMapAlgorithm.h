#ifndef FALL_MAP_ALGORITHM_H
#define FALL_MAP_ALGORITHM_H

#include"../../../../../Base/Graphic/Map/Map.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapGenerateAlgorithm.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapAlgorithm.h"
#include "../../../../../Base/Scheduler/Event/Effect/Effect.h"
#include "../../../../../Base/Scheduler/Event/Effect/EffectMapper.h"



using namespace Base::Graphic::Maps;
using namespace Base::Schedulers::Events::Effects::Algorithms;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers::Events::Effects;
using namespace Meteor::Schedulers::Events::Effects;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class FallMapAlgorithm: public MapAlgorithm<FallEffect>
	{

		bool constructed;

	public:

		/// <summary>
		/// 無功用的建構子，要搭配lazy construct
		///	</summary>
		FallMapAlgorithm();

		int LazyConstruct(int w, int h);

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		FallMapAlgorithm(int w, int h);

	};

	class FallMapGenerateAlgorithm : public MapGenerateAlgorithm<FallEffect> {

		/// <summary>
		/// 把evnet的狀態轉成圖案
		///	</summary>
		virtual int Generate(Map* m, EffectMapper<FallEffect>* em);

	};
	

}}}}}








#endif