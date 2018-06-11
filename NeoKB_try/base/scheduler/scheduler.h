#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include "Event/Event.h"
#include "Event/EventProcessor.h"
#include <functional>
#include "../../Util/Hierachal/ChildAddable.h"


using namespace std;
using namespace Base::Schedulers::Events;
using namespace Util::Hierachal;


namespace Base {
namespace Schedulers {

	/// <summary>
	/// to watch if a timing task is up
	/// </summary>
	class Scheduler: public Updatable, public ChildAddable {

		int tid;

		vector<EventProcessor<Event>*>* eventProcessors;

		/// <summary>
		/// let the processor master to register the handler for every Event
		/// ---(¤£¥Î¤F)int (*deliverHandler)(EventProcessor<Event>* ep);
		/// </summary>
		function<int(EventProcessor<Event>*)> deliverHandler;

	public:

		Scheduler();

		~Scheduler();

		int Add(EventProcessor<Event>* ep);

		int AddRange(vector<EventProcessor<Event>*>* eps);

		int RegisterHandler(function<int(EventProcessor<Event>*)> dh);

		virtual int Elapse(MTO_FLOAT elapsedTime);
	};

}}

#endif