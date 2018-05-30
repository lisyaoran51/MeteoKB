#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <fstream>
#include <vector>
#include "../Event.h"


using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
	

	class Effect: public Event
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		Effect(
			int x,
			int y,
			MTO_FLOAT start_t,
			MTO_FLOAT life_t
		);

		int SetBrightness();
		int SetSpeed();

	protected:

		int x;
		int y;
		MTO_FLOAT brightness;	// default as 1.0
		MTO_FLOAT speed;		// default as 1.0
	};



	

}}}}



#endif