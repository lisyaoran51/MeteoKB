#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "../../Util/MtoType.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Schedulers {
namespace Events {
	

	class Event
	{

	public:

		void Elapse(MTO_FLOAT sec);

		void is_alive();

		int virtual register_handler(void* h);

	protected:

		int eid;

		EventStartType start_type;
		EventElapseType elapse_type;

		MTO_FLOAT start_time;
		MTO_FLOAT life_time;

		/// ???
		(void*)handler(Event* self);
	};

	enum EventStartType {
		Immediate,
		Reserved
	};

	enum EventElapseType {
		OneTime,
		Longterm,
		BySignal
	};

	

}}}



#endif