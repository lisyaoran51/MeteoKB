#ifndef WORKING_SHEETMUSIC_H
#define WORKING_SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "Sheetmusic.h"
#include "SheetmusicInfo.h"



using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;

namespace Base {
namespace Sheetmusics {

	/// where T : effect_group
	/// 
	class WorkingSm
	{

		sm_info_t* sm_info;

		sm_metadata_t* sm_metadata;

		vector<ctrl_point>* effects;

		vector<mod_t*> mods;

		Sm<Event>* sm;

	public:

		Sm<Event>* GetSm();

	protected:

		WorkingSm(sm_info_t* s);

		virtual Sm<Event>* create_sm() = 0;

	};


}
}



#endif