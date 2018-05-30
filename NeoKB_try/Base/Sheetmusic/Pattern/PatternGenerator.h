#ifndef PATTERN_GENERATOR_H
#define PATTERN_GENERATOR_H



#include <string>
#include <fstream>
#include <vector>
#include "../working_sheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "../sheetmusic_info.h"
#include "../Sheetmusic.h"
#include "../../Scheduler/Event/Event.h"




using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusic;

namespace Base {
namespace Sheetmusic {
namespace Patterns {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class PatternGenerator
	{

	public:

		virtual Pattern* generate() = 0;

	protected:

		int map_width;

		int map_height;

		PatternGenerator* previous_pattern;

		Event* Event;

		Sm<Event>* sm;



	};


}}}







#endif