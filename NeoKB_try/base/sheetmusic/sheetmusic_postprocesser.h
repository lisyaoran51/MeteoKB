#ifndef SHEETMUSIC_POSTPROCESSOR_H
#define SHEETMUSIC_POSTPROCESSOR_H


#include "sheetmusic.h"
#include "../scheduler/event/event.h"


using namespace std;
using namespace Util;
using namespace base::scheduler::event;



namespace base {
namespace sheetmusic {

	/// <summary>
	/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z�A�Ҧp����event���s�Ƨ�
	///	</summary>
	class sm_postprocessor_t
	{

	public:

		/// <summary>
		/// �b�C��load�i�q���åB�ഫ�H��A�o�ӥi�H���@�ǫ�B�z
		///	</summary>
		virtual sm_t<event_t>* postprocess(sm_t<event_t>* s) {
			return s;
		}


	};


}
}





#endif