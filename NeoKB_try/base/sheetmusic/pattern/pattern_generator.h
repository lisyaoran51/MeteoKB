#ifndef PATTERN_GENERATOR_H
#define PATTERN_GENERATOR_H



#include <string>
#include <fstream>
#include <vector>
#include "../working_sheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "../sheetmusic_info.h"
#include "../sheetmusic.h"
#include "../../Scheduler/Event/Event.h"




using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;
using namespace Base::sheetmusic;

namespace Base {
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

		Event* Event;

		sm_t<Event>* sm;



	};


}}}







#endif