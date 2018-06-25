#ifndef EXPLODE_MAP_ALGORITHM_H
#define EXPLODE_MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapAlgorithm.h"
#include "../../../../../Base/Scheduler/Event/Event.h"
#include "../ExplodeEffectMapper.h"
#include "../ExplodeEffect.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapGenerateAlgorithm.h"


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
	
	class ExplodeMapAlgorithm: public MapAlgorithm<ExplodeEffect>
	{

		bool constructed;

	public:

		/// <summary>
		/// 無功用的建構子，要搭配lazy construct
		///	</summary>
		ExplodeMapAlgorithm();

		int LazyConstruct(int w, int h);

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		ExplodeMapAlgorithm(int w, int h);

	};


	class ExplodeMapGenerateAlgorithm : public MapGenerateAlgorithm<ExplodeEffect> {
		
		/// <summary>
		/// 把evnet的狀態轉成圖案
		///	</summary>
		virtual int Generate(Map* m, EffectMapper<ExplodeEffect>* em);

	};
	

}}}}}








#endif