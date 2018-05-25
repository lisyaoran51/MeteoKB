#ifndef WORKING_SHEETMUSIC_H
#define WORKING_SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/template_constraint.h"



using namespace std;
using namespace Util;

namespace base {
namespace sheetmusic {

	/// where T : effect_group
	/// 
	class working_sm_t
	{

		sm_info_t* sm_info;

		sm_metadata_t* sm_metadata;

		vector<ctrl_point>* effects;

		vector<mod_t*> mods;

		sm_t* sm;

	public:

		sm_t* get_sm();

	protected:

		working_sm_t(sm_info_t* s);

		virtual sm_t* create_sm() = 0;

	};


}
}



#endif