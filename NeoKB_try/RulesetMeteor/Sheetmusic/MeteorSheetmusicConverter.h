#ifndef METEOR_SHEETMUSIC_CONVERTER_H
#define METEOR_SHEETMUSIC_CONVERTER_H

#include"../../Base/Sheetmusic/SheetmusicConverter.h"

using namespace Base::Sheetmusics;


namespace Meteor {
namespace Sheetmusics{

	class MeteorSmConverter : public SmConverter {

		

	protected:
		/// <summary>
		/// ��]�wŪ�i��
		///	</summary>
		MeteorSmConverter(PatternGenerator* pg);

		int convertEvent(vector<Event*>* es, Event* e);

	};


}
}






#endif