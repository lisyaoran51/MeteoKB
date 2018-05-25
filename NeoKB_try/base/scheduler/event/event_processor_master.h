#ifndef EVENT_PROCESSOR_MASTER_H
#define EVENT_PROCESSOR_MASTER_H

#include <string>
#include <map>
#include <vector>
#include "../../Util/template_constraint.h"
#include "../../Util/MtoType.h"
#include "../../Util/instance_creator.h"
#include "../updatable.h"
#include "event.h"
#include "event_processor.h"


using namespace std;
using namespace Util;
using namespace base::scheduler::event;

/*
* instantiate a class with its name in string
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
*/


namespace base {
namespace scheduler {
namespace event {

	/// <summary>
	/// a processor center to process every event including effects, 
	/// </summary>
	class event_processor_master_t : public Updatable
	{
		// for thread
		int tid;

	public:

		int receive_event(event_t* e);

		/// <summary>
		/// When master receive a event, he asks the event's typename. 
		/// Use the typename to register a corresponding processor for this event.
		/// </summary>
		template<class T>
		int register_event_processor();

		int register_map(map_t* m);

		/// <summary>
		/// clean the map, event, processors
		/// </summary>
		int clean();

	protected:

		vector<event_t*>* events;

		int process_event();

		int clean_ended_event();

		/// <summary>
		/// a utility to create new processor with specific type 
		/// </summary>
		instance_creator_t<event_processor_t<event_t>> event_processor_creator;

		vector<event_processor_t<event_t>*> event_processors;

		map_t* map;

	};




}}}



#endif