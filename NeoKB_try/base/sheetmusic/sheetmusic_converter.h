#ifndef SHEETMUSIC_CONVERTER_H
#define SHEETMUSIC_CONVERTER_H

#include <string>
#include <fstream>
#include <vector>
#include "working_sheetmusic.h"
#include "../../Util/template_constraint.h"
#include "sheetmusic_info.h"
#include "sheetmusic.h"
#include "../scheduler/event/event.h"




using namespace std;
using namespace Util;
using namespace base::scheduler::event;

namespace base {
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
		virtual sm_t<event_t>* convert(sm_t<event_t>* s);

	protected:

		virtual vector<event_t*>* convert_event(event_t* e, sm_t<event_t>* s) = 0;

	};


}
}



#endif