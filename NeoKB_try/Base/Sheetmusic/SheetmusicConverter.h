#ifndef SHEETMUSIC_CONVERTER_H
#define SHEETMUSIC_CONVERTER_H

#include <string>
#include <fstream>
#include <vector>
#include "working_sheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "sheetmusic_info.h"
#include "Sheetmusic.h"
#include "../Scheduler/Event/Event.h"




using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;

namespace Base {
namespace Sheetmusic {

	/// <summary>
	/// when Ruleset executor load in sm, this converter converts the events in sm.
	///	</summary>
	class SmConverter
	{
		/// <summary>
		/// 讀取pattern generator
		///	</summary>
		int load();
		int load(PatternGenerator* pg);

	public:

		/// <summary>
		/// converts the events in sm
		/// We always operate on a clone of the original sm, to not modify it game-wide
		///	</summary>
		virtual Sm<Event>* convert(Sm<Event>* s);

	protected:

		/// <summary>
		/// 用來把一個event變成各種特效
		///	</summary>
		PatternGenerator* patternGenerator;

		/// <summary>
		/// 把event付智，並且轉換成各種特效
		///	</summary>
		virtual int convert_event(vector<Event*>* es, Event* e, Sm<Event>* s);

	};


}
}



#endif