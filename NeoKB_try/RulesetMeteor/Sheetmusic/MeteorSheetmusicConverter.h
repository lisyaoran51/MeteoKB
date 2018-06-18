#ifndef METEOR_SHEETMUSIC_CONVERTER_H
#define METEOR_SHEETMUSIC_CONVERTER_H

#include"../../Base/Sheetmusic/SheetmusicConverter.h"

using namespace Base::Sheetmusics;


namespace Meteor {
namespace Sheetmusics{

	class MeteorSmConverter : public SmConverter {

		

	protected:
		/// <summary>
		/// 把設定讀進來
		///	</summary>
		MeteorSmConverter(PatternGenerator* pg);

		int convertEvent(vector<Event*>* es, Event* e);

	};


}
}






#endif