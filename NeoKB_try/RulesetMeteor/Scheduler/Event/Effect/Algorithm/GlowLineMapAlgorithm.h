#ifndef GLOWLINE_MAP_ALGORITHM_H
#define GLOWLINE_MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"


using namespace Base::Graphic::Maps;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	class GlowLineMapAlgorithm: public MapAlgorithm<GlowLineEffectMapper>
	{

	public:

		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		int Draw(Map* m, GlowLineEffectMapper* e);


	};



	

}}}}}








#endif