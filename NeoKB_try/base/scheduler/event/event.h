#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../util/template_constraint.h"
#include "../../config/type.h"



using namespace std;
using namespace util;

namespace base {
namespace scheduler {
namespace event {
	

	class event_t
	{

	public:

		void elapse(MTO_FLOAT sec);

		void is_alive();

		int virtual register_handler(void* h);

	protected:

		event_start_type start_type;
		event_elapse_type elapse_type;

		MTO_FLOAT* start_time;
		MTO_FLOAT* life_time;
		MTO_FLOAT* time_left;

		(void*)handler(event_t* self);
	};

	enum event_start_type {
		immediate,
		reserved
	};

	enum event_elapse_type {
		one_time,
		longterm
	};

	

}}}



#endif