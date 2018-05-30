#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <string>
#include <map>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "../../Util/MtoType.h"
#include "../updatable.h"
#include "Event.h"


using namespace std;
using namespace Util;



namespace Base {
namespace Schedulers {
namespace Events {

	/// <summary>
	/// a processor to process one Event including effects, 
	/// </summary>
	template<class T>
	class EventProcessor : public Updatable, private TConstraint<Event>
	{


	public:

		/// <summary>
		/// When master receive a Event, he asks the Event's typename. 
		/// Use the typename to register a corresponding processor for this Event.
		/// </summary>
		virtual static string get_event_type_name() = 0;
		
		/// <summary>
		/// register the Event to be processed.
		/// </summary>
		int RegisterEvent(T* e);

		/// <summary>
		/// the work to do with this Event, such as stop the game, slow down...
		/// </summary>
		virtual int Process() = 0;

		MTO_FLOAT GetStartTime();
		

	protected:

		/// <summary>
		/// Event id
		/// </summary>
		int eid;

		T* event;

	};




}}}



#endif