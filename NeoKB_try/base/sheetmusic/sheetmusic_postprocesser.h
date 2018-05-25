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
	/// 在遊戲load進歌曲並且轉換以後，這個可以做一些後處理，例如說把event重新排序
	///	</summary>
	class sm_postprocessor_t
	{

	public:

		/// <summary>
		/// 在遊戲load進歌曲並且轉換以後，這個可以做一些後處理
		///	</summary>
		virtual sm_t<event_t>* postprocess(sm_t<event_t>* s) {
			return s;
		}


	};


}
}





#endif