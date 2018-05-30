#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include "Event/Event.h"
#include "Event/EventProcessor.h"
#include "Updatable.h"

using namespace std;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers;

namespace Base {
namespace Schedulers {

	/// <summary>
	/// to watch if a timing task is up
	/// </summary>
	class Scheduler: public Updatable {

		int tid;

		vector<EventProcessor<Event>*>* eventProcessors;

		/// <summary>
		/// let the processor master to register the handler for every Event
		/// </summary>
		int (*deliverHandler)(EventProcessor<Event>* ep);

	public:

		Scheduler();

		~Scheduler();

		int Add(EventProcessor<Event>* ep);

		int AddRange(vector<EventProcessor<Event>*>* eps);

		int RegisterHandler(int(*h)(EventProcessor<Event>*));
	};

}}

#endif