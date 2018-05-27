#ifndef MAPPER_H
#define MAPPER_H


#include "../../../Scheduler/Event/EventProcessor.h"
#include "../../../Scheduler/Event/Effect/Effect.h"

using namespace Base::Scheduler::Event;
using namespace Base::Scheduler::Event::effect;

namespace Base {
namespace Scheduler {
namespace Event {
namespace effect {

	template<class T>
	class EffectMapper : public EventProcessor<Effect>, private TConstraint<T, Effect> {


	public:

		EffectMapper(int w, int h);

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		int RegisterMap(Map* m);

		int RegisterMapAlgo(MapAlgorithm<T>* ma);

		int RegisterShiftAlgo(ShiftAlgorithm* sa);

	protected:

		Map* map;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		MapAlgorithm<T>* mapAlgo;

		/// <summary>
		/// 把生好的effect移到他該擺的位置上
		/// </summary>
		ShiftAlgorithm* shiftAlgo;
	};


}}}}




#endif