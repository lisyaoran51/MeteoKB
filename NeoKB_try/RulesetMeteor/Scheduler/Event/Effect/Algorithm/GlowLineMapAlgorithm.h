#ifndef GLOWLINE_MAP_ALGORITHM_H
#define GLOWLINE_MAP_ALGORITHM_H

#include "../../../../../Base/Graphic/Map/Map.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapGenerateAlgorithm.h"
#include "../../../../../Base/Scheduler/Event/Effect/Algorithm/MapAlgorithm.h"
#include "../GlowLineEffect.h"
#include "../GlowLineEffectMapper.h"


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
	
	class GlowLineMapAlgorithm: public MapAlgorithm<GlowLineEffect>
	{

		bool constructed;

	public:

		/// <summary>
		/// 無功用的建構子，要搭配lazy construct
		///	</summary>
		GlowLineMapAlgorithm();

		int LazyConstruct(int w, int h);

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		GlowLineMapAlgorithm(int w, int h);

	};

	class GlowLineMapGenerateAlgorithm : public MapGenerateAlgorithm<GlowLineEffect> {

		/// <summary>
		/// 把evnet的狀態轉成圖案
		///	</summary>
		virtual int Generate(Map* m, EffectMapper<GlowLineEffect>* em);

	};

	

}}}}}








#endif