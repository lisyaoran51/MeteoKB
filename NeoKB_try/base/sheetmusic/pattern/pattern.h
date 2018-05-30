#ifndef PATTERN_H
#define PATTERN_H


#include <vector>
#include "../../Scheduler/Event/Event.h"


using namespace std;
using namespace Base::Scheduler::Event;


namespace Base {
namespace Sheetmusic {
namespace pattern {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class Pattern
	{

	public:

		int add(Event* e);

		vector<Event*>* get_events();

	protected:

		vector<Event*>* events;

	};


}}}


#endif
