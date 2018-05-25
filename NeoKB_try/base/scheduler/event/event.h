#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/template_constraint.h"
#include "../../Util/MtoType.h"



using namespace std;
using namespace Util;

namespace base {
namespace scheduler {
namespace event {
	

	class event_t
	{

	public:

		/// <summary>
		/// When master receive a event, he asks the event's typename. 
		/// Use the typename to register a corresponding processor for this event.
		/// </summary>
		static string get_event_type_name();

		void elapse(MTO_FLOAT sec);

		void is_alive();

		int virtual register_handler(void* h);

	protected:

		int eid;

		event_start_type_t start_type;
		event_elapse_type_t elapse_type;

		MTO_FLOAT* start_time;
		MTO_FLOAT* life_time;
		MTO_FLOAT* time_left;

		/// ???
		(void*)handler(event_t* self);
	};

	enum event_start_type_t {
		immediate,
		reserved
	};

	enum event_elapse_type_t {
		one_time,
		longterm
	};

	

}}}



#endif