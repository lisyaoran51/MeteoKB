#ifndef METEOR_SHEETMUSIC_CONVERTER_H
#define METEOR_SHEETMUSIC_CONVERTER_H

#include"../../Base/Sheetmusic/SheetmusicConverter.h"

using namespace Base::Sheetmusic;


namespace Meteor {
namespace Sheetmusic{

	class MeteorSmConverter : public SmConverter {

		/// <summary>
		/// ��]�wŪ�i��
		///	</summary>
		int load();

	protected:

		int convert_event(vector<Event*>* es, Event* e, Sm<Event>* s);

	};


}
}






#endif