#ifndef MAPPER_H
#define MAPPER_H


#include "../../../Scheduler/Event/EventProcessor.h"
#include "../../../Scheduler/Event/Effect/Effect.h"
#include "Algorithm/MapAlgorithm.h"

using namespace Base::Schedulers::Events;
using namespace Base::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events::Effects::Algorithms;

namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {

	template<class T>
	class EffectMapper : public EventProcessor<Event>, private TConstraint<T, Effect> {

	public:

		EffectMapper(int w, int h);

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		int RegisterMap(Map* m);

		int RegisterMapAlgorithm(MapAlgorithm<T>* ma);

		int GetWidth();
		int GetHeight();
		int GetX();
		int GetY();
		MTO_FLOAT GetSpeed();

	protected:

		T* effect;

		Map* map;

		MapAlgorithm<T>* mapAlgo;

		int width, height;

	};


}}}}




#endif