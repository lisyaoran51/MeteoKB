#ifndef SHEETMUSIC_MANAGER_H
#define SHEETMUSIC_MANAGER_H

#include <string>
#include <fstream>
#include <vector>
#include "working_sheetmusic.h"
#include "../../Util/TemplateConstraint.h"
#include "sheetmusic_info.h"
#include "Sheetmusic.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Sheetmusic {

	/// where T : effect_group
	/// 
	class SmManager
	{

		static int copy_to(ifstream* from, ifstream* to);

	public:

		SmManager();

		int import(vector<string>* path);

		WorkingSm* get_working_sm(sm_info_t* s);

	protected:

		vector<sm_info_t*>* sm_info;

		vector<sm_info_t*>* import(ifstream* file_stream);

		vector<sm_info_t*>* import_to_storage(ifstream* file_stream);

		// WorkingSm(sm_info_t* s);

		virtual Sm<effect_group_t>* create_sm() = 0;

	};


}
}



#endif