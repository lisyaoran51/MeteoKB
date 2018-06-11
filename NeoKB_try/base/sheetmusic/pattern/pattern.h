#ifndef PATTERN_H
#define PATTERN_H


#include <vector>
#include "../../Scheduler/Event/Event.h"


using namespace std;
using namespace Base::Schedulers::Events;


namespace Base {
namespace Sheetmusics {
namespace Patterns {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class Pattern : public MtoObject
	{

	public:

		int add(Event* e);

		vector<Event*>* get_events();

	protected:

		vector<Event*>* events;

	};


}}}


#endif
