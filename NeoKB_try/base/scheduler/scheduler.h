#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include "Event/Event.h"
#include "Event/EventProcessor.h"
#include "Updatable.h"

using namespace std;
using namespace Base::Scheduler::Event;
using namespace Base::Scheduler;

namespace Base {
namespace Scheduler {

	/// <summary>
	/// to watch if a timing task is up
	/// </summary>
	class Scheduler: public Updatable {

		int tid;

		vector<EventProcessor*>* eventProcessors;

		/// <summary>
		/// let the processor master to register the handler for every Event
		/// </summary>
		int (*deliverHandler)(EventProcessor* ep);

	public:

		Scheduler();

		~Scheduler();

		int Add(EventProcessor* ep);

		int AddRange(vector<EventProcessor*>* eps);

		int RegisterHandler(int(*h)(EventProcessor*));
	};

}}

#endif