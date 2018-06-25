#ifndef FALL_EFFECT_H
#define FALL_EFFECT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../../../Base/Scheduler/Event/Effect/Effect.h"


using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events::Effects;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {
	

	class FallEffect: public Effect
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		FallEffect(
			int xPos,
			int yPos,
			MTO_FLOAT sTime,
			MTO_FLOAT l,
			MTO_FLOAT sp
		);

		// 一定要每次都override!!
		virtual string GetTypeName();

	protected:
	};



	

}}}}



#endif