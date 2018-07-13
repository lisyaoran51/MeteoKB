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

	class EffectMapperInterface : public EventProcessor<Event>{

	public:

		EffectMapperInterface(int w, int h);

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		virtual int RegisterMap(Map* m) = 0;

		virtual int RegisterMapAlgorithm(MapAlgorithmInterface* ma) = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual int GetX() = 0;
		virtual int GetY() = 0;
		virtual MTO_FLOAT GetSpeed() = 0;


	};




	template<class T>
	class EffectMapper : public EffectMapperInterface, private TConstraint<T, Effect> {

	public:

		EffectMapper(int w, int h);

		virtual int Elapse(MTO_FLOAT elaspedTime);

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		int RegisterMap(Map* m);

		virtual int RegisterMapAlgorithm(MapAlgorithmInterface* ma);

		virtual int GetWidth();
		virtual int GetHeight();
		virtual int GetX();
		virtual int GetY();
		virtual MTO_FLOAT GetSpeed();

	protected:

		T* effect;

		Map* lightMap;

		MapAlgorithm<T>* mapAlgo;

		int width, height;

	};


}}}}




#endif