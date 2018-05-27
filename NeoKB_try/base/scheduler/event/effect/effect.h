#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <fstream>
#include <vector>
#include "../Event.h"


using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;


namespace Base {
namespace Scheduler {
namespace Event {
namespace effect {
	

	class Effect: public Event
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		Effect( 
			int p, 
			MTO_FLOAT v,
			MTO_FLOAT s,
			MTO_FLOAT life_t
		);

		/// <summary>
		/// construct a reserved effect
		///	</summary>
		Effect(
			int p,
			MTO_FLOAT v,
			MTO_FLOAT s,
			MTO_FLOAT start_t,
			MTO_FLOAT life_t
		);


	protected:

		int pitch;
		MTO_FLOAT vol;
		MTO_FLOAT speed;
	};



	

}}}}



#endif