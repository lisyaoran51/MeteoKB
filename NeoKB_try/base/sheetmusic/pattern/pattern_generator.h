#ifndef PATTERN_GENERATOR_H
#define PATTERN_GENERATOR_H



#include <string>
#include <fstream>
#include <vector>
#include "../working_sheetmusic.h"
#include "../../Util/template_constraint.h"
#include "../sheetmusic_info.h"
#include "../sheetmusic.h"
#include "../../scheduler/event/event.h"




using namespace std;
using namespace Util;
using namespace base::scheduler::event;
using namespace base::sheetmusic;

namespace base {
namespace sheetmusic {
namespace pattern {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class pattern_generator_t
	{

	public:

		virtual pattern_t* generate() = 0;

	protected:

		int map_width;

		int map_height;

		pattern_generator_t* previous_pattern;

		event_t* event;

		sm_t<event_t>* sm;



	};


}}}







#endif