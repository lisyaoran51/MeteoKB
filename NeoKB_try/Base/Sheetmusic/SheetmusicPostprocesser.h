#ifndef SHEETMUSIC_POSTPROCESSOR_H
#define SHEETMUSIC_POSTPROCESSOR_H


#include "sheetmusic.h"
#include "../Scheduler/Event/Event.h"


using namespace std;
using namespace Util;
using namespace Base::Scheduler::Event;



namespace Base {
namespace sheetmusic {

	/// <summary>
	/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z�A�Ҧp����Event���s�Ƨ�
	///	</summary>
	class sm_postprocessor_t
	{

	public:

		/// <summary>
		/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z
		///	</summary>
		virtual sm_t<Event>* postprocess(sm_t<Event>* s) {
			return s;
		}


	};


}
}





#endif