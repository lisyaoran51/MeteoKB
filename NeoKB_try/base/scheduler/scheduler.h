#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include "event/event.h"
#include "event/event_processor.h"
#include "Updatable.h"

using namespace std;
using namespace base::scheduler::event;
using namespace base::scheduler;

namespace base {
namespace scheduler {

	/// <summary>
	/// to watch if a timing task is up
	/// </summary>
	class scheduler_t: public Updatable {

		int tid;

		vector<event_processor_t*>* events;

		vector<event_processor_t*>* running_events;

		/// <summary>
		/// let the processor to register the handler for every event
		/// </summary>
		int* event_handler(event_t* e);

	public:

		int add(event_processor_t* e);

		int add_range(vector<event_processor_t*>* es);

		int register_handler(void* h);
	};

}}

#endif