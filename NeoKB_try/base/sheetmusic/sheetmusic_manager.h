#ifndef SHEETMUSIC_MANAGER_H
#define SHEETMUSIC_MANAGER_H

#include <string>
#include <fstream>
#include <vector>
#include "working_sheetmusic.h"
#include "../../Util/template_constraint.h"
#include "sheetmusic_info.h"
#include "sheetmusic.h"



using namespace std;
using namespace Util;

namespace base {
namespace sheetmusic {

	/// where T : effect_group
	/// 
	class sm_manager_t
	{

		static int copy_to(ifstream* from, ifstream* to);

	public:

		sm_manager_t();

		int import(vector<string>* path);

		working_sm_t* get_working_sm(sm_info_t* s);

	protected:

		vector<sm_info_t*>* sm_info;

		vector<sm_info_t*>* import(ifstream* file_stream);

		vector<sm_info_t*>* import_to_storage(ifstream* file_stream);

		// working_sm_t(sm_info_t* s);

		virtual sm_t<effect_group_t>* create_sm() = 0;

	};


}
}



#endif