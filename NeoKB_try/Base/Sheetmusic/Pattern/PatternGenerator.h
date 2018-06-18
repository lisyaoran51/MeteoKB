#ifndef PATTERN_GENERATOR_H
#define PATTERN_GENERATOR_H



#include <string>
#include <fstream>
#include <vector>
#include <functional>
#include "../WorkingSheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "../SheetmusicInfo.h"
#include "../Sheetmusic.h"
#include "../../Scheduler/Event/Event.h"
#include "pattern.h"
#include "../../../Util/MtoObject.h"




using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics;

namespace Base {
namespace Sheetmusics {
namespace Patterns {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class PatternGenerator: public Loadable
	{

		int load();

		int load(FrameworkConfigManager* fConfigManager);

	public:

		PatternGenerator();

		~PatternGenerator();

		virtual Pattern* Generate(vector<Event*> es, Event * e) = 0;

		int Add(Pattern* p);

		int CleanPatterns();

	protected:

		int width;

		int height;

		int blackKeyHeight;

		Pitch startPitch;

		vector<Pattern*> patterns;

		Event* event;

		//Sm<Event>* sm;

	};


}}}







#endif