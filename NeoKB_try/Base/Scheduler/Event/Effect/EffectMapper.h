#ifndef MAPPER_H
#define MAPPER_H


#include "../../../Scheduler/Event/EventProcessor.h"
#include "../../../Scheduler/Event/Effect/Effect.h"
#include "Algorithm/MapAlgorithm.h"
#include <stdexcept>


using namespace Base::Schedulers::Events;
using namespace Base::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events::Effects::Algorithms;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {

	class EffectMapperInterface : public EventProcessor<Event>{

	public:

		EffectMapperInterface(): EventProcessor<Event>()
		{
		}

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

		EffectMapper(int w, int h): EffectMapperInterface(){
			width = w;
			height = h;
			// 把effect的功能打開，擺在effect
			effect = dynamic_cast<T*>(event);
		}

		virtual int Elapse(MTO_FLOAT elapsedTime) {

			if (!lightMap)
				throw runtime_error("int EffectMapper::Process() : no map registered!");

			if (!mapAlgo)
				throw runtime_error("int EffectMapper::Process() : no map algorithm registered!");

			// current time從effect開始播放時，從0開始計算，直到current time超過life time時，特效結束
			currentTime += elapsedTime;

			mapAlgo->Draw(lightMap, this);

			return 0;
		}

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		int RegisterMap(Map* m) {
			lightMap = m;

			return 0;
		}

		virtual int RegisterMapAlgorithm(MapAlgorithmInterface* ma) {
			if (MtoObject::CanCast<MapAlgorithm<T>>(ma)) {
				mapAlgo = MtoObject::Cast<MapAlgorithm<T>>(ma);
				return 0;
			}
			else {
				// TODO: 怎麼噴錯誤?
				return -1;
			}
		}

		virtual int GetWidth() { return width; }
		virtual int GetHeight() { return height; }
		virtual int GetX(){ return effect->GetX(); }
		virtual int GetY(){ return effect->GetY(); }
		virtual MTO_FLOAT GetSpeed(){ return effect->GetSpeed(); }

	protected:

		T* effect;

		Map* lightMap;

		MapAlgorithm<T>* mapAlgo;

		int width, height;

	};


}}}}




#endif