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
#include "../../Util/MtoObject.h"
#include "Pattern\PatternGenerator.h"
#include "../../Util/Hierachal/ChildAddable.h"




using namespace std;
using namespace Util;
using namespace Util::Hierachal;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics::Patterns;

namespace Base {
namespace Sheetmusics {

	/// <summary>
	/// when Ruleset executor load in sm, this converter converts the events in sm.
	///	</summary>
	class SmConverter: public ChildAddable
	{
		/// <summary>
		/// Ū��pattern generator
		///	</summary>
		int load();
		int load(PatternGenerator* pg);

	public:

		/// <summary>
		/// converts the events in sm
		/// We always operate on a clone of the original sm, to not modify it game-wide
		///	</summary>
		virtual Sm<Event>* Convert(Sm<Event>* s);

	protected:

		/// <summary>
		/// �Ψӧ�@��event�ܦ��U�دS��
		///	</summary>
		PatternGenerator* patternGenerator;

		/// <summary>
		/// ��event�I���A�åB�ഫ���U�دS��
		///	</summary>
		virtual int convert_event(vector<Event*>* es, Event* e, Sm<Event>* s);

	};


}
}



#endif