#ifndef MAP_GENERATE_ALGORITHM_H
#define MAP_GENERATE_ALGORITHM_H

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
	
	class MapGenerateAlgorithmInterface {

	public:

		// EventProcessor<Event> = EffectMapper<T>
		// �]��template���వ�h���A�ҥH�h���@�hinterface�X��
		/// <summary>
		/// ��evnet�����A�ন�Ϯ�
		///	</summary>
		virtual int Generate(Map* m, EventProcessor<Event>* em) = 0;
		
	};


	/// <summary>
	/// �e�X�S��
	///	</summary>
	template<typename T>
	class MapGenerateAlgorithm: public MapGenerateAlgorithmInterface
	{
		
	public:
		/// <summary>
		/// ��evnet�����A�ন�Ϯ�
		///	</summary>
		virtual int Generate(Map* m, EventProcessor<Event>* em);

	protected:
		/// <summary>
		/// ��evnet�����A�ন�Ϯ�
		///	</summary>
		virtual int ImplementGenerate(Map* m, EffectMapper<T>* em) = 0;


	};
	

}}}}}








#endif