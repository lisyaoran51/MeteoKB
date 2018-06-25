#ifndef MAP_GENERATE_ALGORITHM_H
#define MAP_GENERATE_ALGORITHM_H

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
	class MapGenerateAlgorithm
	{

	public:
		/// <summary>
		/// ��evnet�����A�ন�Ϯ�
		///	</summary>
		virtual int Generate(Map* m, EffectMapper<T>* em) = 0;

	};
	

}}}}}








#endif