#ifndef EXPLODE_EFFECT_H
#define EXPLODE_EFFECT_H

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
	

	class ExplodeEffect: public Effect
	{

	public:

		/// <summary>
		/// 這個建構子不是用來執行的，指示用來給TConstraint來確認繼承關係用
		///	</summary>
		ExplodeEffect();

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		ExplodeEffect(
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