#ifndef SHEETMUSIC_POSTPROCESSOR_H
#define SHEETMUSIC_POSTPROCESSOR_H


#include "Sheetmusic.h"
#include "../Scheduler/Event/Event.h"


using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;



namespace Base {
namespace Sheetmusics {

	/// <summary>
	/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z�A�Ҧp����Event���s�Ƨ�
	///	</summary>
	class SmPostprocessor
	{

	public:

		/// <summary>
		/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z
		///	</summary>
		virtual Sm<Event>* postprocess(Sm<Event>* s) {
			return s;
		}


	};


}
}





#endif