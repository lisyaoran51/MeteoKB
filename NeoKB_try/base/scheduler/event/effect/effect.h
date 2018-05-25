#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <fstream>
#include <vector>
#include "../event.h"


using namespace std;
using namespace Util;
using namespace base::scheduler::event;


namespace base {
namespace scheduler {
namespace event {
namespace effect {
	

	class effect_t: public event_t
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		effect_t( 
			int p, 
			MTO_FLOAT v,
			MTO_FLOAT s,
			MTO_FLOAT life_t
		);

		/// <summary>
		/// construct a reserved effect
		///	</summary>
		effect_t(
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