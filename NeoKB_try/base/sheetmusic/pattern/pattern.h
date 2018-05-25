#ifndef PATTERN_H
#define PATTERN_H


#include <vector>
#include "../../scheduler/event/event.h"


using namespace std;
using namespace base::scheduler::event;


namespace base {
namespace sheetmusic {
namespace pattern {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class pattern_t
	{

	public:

		int add(event_t* e);

		vector<event_t*>* get_events();

	protected:

		vector<event_t*>* events;

	};


}}}


#endif
