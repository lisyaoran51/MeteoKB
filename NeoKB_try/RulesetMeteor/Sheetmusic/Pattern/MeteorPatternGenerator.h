#ifndef METEOR_PATTERN_GENERATOR_H
#define METEOR_PATTERN_GENERATOR_H



#include <string>
#include <fstream>
#include <vector>
#include "../../../Base/Sheetmusic/Pattern/Pattern.h"
#include "../../../Base/Sheetmusic/Pattern/PatternGenerator.h"
#include "../../Config/MeteorConfigManager.h"




using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics;
using namespace Meteor::Config;
using namespace Base::Sheetmusics::Patterns;

namespace Meteor {
namespace Sheetmusics {
namespace Patterns {

	/// <summary>
	/// to generate special pattern from original events
	///	</summary>
	class MeteorPatternGenerator: public PatternGenerator
	{

		int load();

		int load(MeteorConfigManager* mcf);

	public:

		MeteorPatternGenerator();

		virtual Pattern* Generate(vector<Event*>* es, Event * e);

	protected:

		MTO_FLOAT fallSpeed = 0;
		MTO_FLOAT fallBrightness = 0;
		int fallLength = 0;
		MTO_FLOAT explodeSpeed = 0;
		MTO_FLOAT explodeBrightness = 0;
		MTO_FLOAT glowLineSpeed = 0;
		MTO_FLOAT glowLineDuration = 0;
		MTO_FLOAT glowLineBrightness = 0;
	};


}}}







#endif