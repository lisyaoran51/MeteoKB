#ifndef MAP_SHIFT_ALGORITHM_H
#define MAP_SHIFT_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../../Event.h"
#include "../../EventProcessor.h"

using namespace Base::Graphic::Maps;

namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {

	template<typename T>
	class EffectMapper;

}}}}

using namespace Base::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events;

namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class MapShiftAlgorithmInterface {

	public:

		// EventProcessor<Event> = EffectMapper<T>
		// �]��template���వ�h���A�ҥH�h���@�hinterface�X��
		/// <summary>
		/// ���ʨ���w��m�W
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* lightMap, EventProcessor<Event>* em) = 0;


	};


	/// <summary>
	/// ���ʯS�Ī���m
	///	</summary>
	template<typename T>
	class MapShiftAlgorithm: public MapShiftAlgorithmInterface
	{

	public:
		/// <summary>
		/// ���ʨ���w��m�W
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* lightMap, EventProcessor<Event>* em);

	protected:

		/// <summary>
		/// ���ʨ���w��m�W
		///	</summary>
		virtual int ImplementShift(Map* bufferMap, Map* lightMap, EffectMapper<T>* em);

	};
	

}}}}}








#endif