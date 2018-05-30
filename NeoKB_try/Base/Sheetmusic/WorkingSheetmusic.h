#ifndef WORKING_SHEETMUSIC_H
#define WORKING_SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Sheetmusic {

	/// where T : effect_group
	/// 
	class WorkingSm
	{

		sm_info_t* sm_info;

		sm_metadata_t* sm_metadata;

		vector<ctrl_point>* effects;

		vector<mod_t*> mods;

		Sm* sm;

	public:

		Sm* get_sm();

	protected:

		WorkingSm(sm_info_t* s);

		virtual Sm* create_sm() = 0;

	};


}
}



#endif