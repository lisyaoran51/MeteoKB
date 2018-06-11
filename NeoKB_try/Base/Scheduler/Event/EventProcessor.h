#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <string>
#include <map>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "../../Util/MtoType.h"
#include "../../../Util/Update/Updatable.h"
#include "Event.h"


using namespace std;
using namespace Util;
using namespace Util::Update;


namespace Base {
namespace Schedulers {
namespace Events {

	/// <summary>
	/// a processor to process one Event including effects, 
	/// </summary>
	template<class T>
	class EventProcessor : public Updatable, private TConstraint<T, Event>
	{


	public:

		
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