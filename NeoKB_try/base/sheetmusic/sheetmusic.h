#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../util/template_constraint.h"



using namespace std;
using namespace util;

namespace base {
namespace sheetmusic {
	
	/// where T : effect_group
	/// 
	template <class T>
	class sm_t : T_constraint_t<effect_group_t>
	{

		sm_info_t* sm_info;
		
		effect_info_t* effect_info;
		
		sm_metadata_t* sm_metadata;
		
		vector<ctrl_point>* effects;

		void constraint_check_derived_from<T>();

	public:
		
		sm_t(sm_t* sm = NULL);

	protected:

	};


}}



#endif