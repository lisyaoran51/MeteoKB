#ifndef FALL_MAP_ALGORITHM_H
#define FALL_MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"


using namespace Base::Graphic::Maps;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class FallMapAlgorithm: public MapAlgorithm<FallEffectMapper>
	{

	public:

		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		int Draw(Map* m, FallEffectMapper* e);


	};



	

}}}}}








#endif