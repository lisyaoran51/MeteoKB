#ifndef SHEETMUSIC_CONVERTER_H
#define SHEETMUSIC_CONVERTER_H

#include <string>
#include <fstream>
#include <vector>
#include "working_sheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "sheetmusic_info.h"
#include "sheetmusic.h"
#include "../Scheduler/Event/Event.h"




using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;

namespace Base {
namespace sheetmusic {

	/// <summary>
	/// when ruleset executor load in sm, this converter converts the events in sm.
	///	</summary>
	class sm_converter_t
	{

	public:

		/// <summary>
		/// converts the events in sm
		/// We always operate on a clone of the original sm, to not modify it game-wide
		///	</summary>
		virtual sm_t<Event>* convert(sm_t<Event>* s);

	protected:

		virtual vector<Event*>* convert_event(Event* e, sm_t<Event>* s) = 0;

	};


}
}



#endif