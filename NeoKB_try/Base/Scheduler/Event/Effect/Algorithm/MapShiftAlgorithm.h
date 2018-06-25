#ifndef MAP_SHIFT_ALGORITHM_H
#define MAP_SHIFT_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"
#include "../EffectMapper.h"

using namespace Base::Graphic::Maps;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	/// <summary>
	/// �e�X�S��
	///	</summary>
	template<typename T>
	class MapShiftAlgorithm
	{

	public:
		/// <summary>
		/// ���ʨ���w��m�W
		///	</summary>
		virtual int Shift(Map* bufferMap, Map* map, EffectMapper<T>* em);

	};
	

}}}}}








#endif