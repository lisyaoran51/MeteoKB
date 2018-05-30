#ifndef EVENT_PROCESSOR_MASTER_H
#define EVENT_PROCESSOR_MASTER_H

#include <string>
#include <map>
#include <vector>
#include "../../../Util/TemplateConstraint.h"
#include "../../../Util/MtoType.h"
#include "../../../Util/InstanceCreator.h"
#include "../../../Util/Update/Updatable.h"
#include "Event.h"
#include "EventProcessor.h"


using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;

/*
* instantiate a class with its name in string
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
*/


namespace Base {
namespace Schedulers {
namespace Events {

	/// <summary>
	/// a processor center to process every Event including effects, 
	/// </summary>
	class EventProcessorMaster : public Updatable
	{
		// for thread
		int tid;

	public:

		int ReceiveEventProcessor(EventProcessor<Event>* ep);

		/* 改成擺在rulset executor裡
		/// <summary>
		/// When master receive a Event, he asks the Event's typename. 
		/// Use the typename to register a corresponding processor for this Event.
		/// </summary>
		template<class T>
		int register_event_processor();
		*/

		int RegisterMap(Map* m);

		/// <summary>
		/// clean the map, Event, processors
		/// </summary>
		int clean();

	protected:

		vector<EventProcessor<Event>*>* eventProcessors;

		int processEvent(MTO_FLOAT elapsedTime);

		int cleanEndedEvent();

		/* 改成擺在rulset executor裡
		/// <summary>
		/// a utility to create new processor with specific type 
		/// </summary>
		InstanceCreator<EventProcessor<Event>> event_processor_creator;
		*/

		vector<EventProcessor<Event>*> event_processors;

		Map* map;

	};




}}}



#endif