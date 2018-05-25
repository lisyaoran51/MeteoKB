#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <string>
#include <map>
#include <vector>
#include "../../Util/template_constraint.h"
#include "../../Util/MtoType.h"
#include "../updatable.h"
#include "event.h"


using namespace std;
using namespace Util;



namespace base {
namespace scheduler {
namespace event {

	/// <summary>
	/// a processor to process one event including effects, 
	/// </summary>
	template<class T>
	class event_processor_t : public Updatable, private T_constraint_t<event_t>
	{


	public:

		/// <summary>
		/// When master receive a event, he asks the event's typename. 
		/// Use the typename to register a corresponding processor for this event.
		/// </summary>
		virtual static string get_event_type_name() = 0;
		
		/// <summary>
		/// register the event to be processed.
		/// </summary>
		int register_event(T* e);

		/// <summary>
		/// the work to do with this event, such as stop the game, slow down...
		/// </summary>
		virtual int process() = 0;

		

	protected:

		/// <summary>
		/// event id
		/// </summary>
		int eid;

		T* event;

	};




}}}



#endif