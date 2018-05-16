#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include "event/event.h"


using namespace std;
using namespace base::scheduler::event;


namespace base {
namespace scheduler {


	class scheduler_t {

		int tid;

		vector<event_t*>* events;

		vector<event_t*>* running_events;

		MTO_FLOAT current_time;

	public:

		int add(event_t* e);

		int add_range(vector<event_t*>* es);



	};

}}

#endif