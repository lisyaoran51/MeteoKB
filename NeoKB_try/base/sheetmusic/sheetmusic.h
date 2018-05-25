#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/template_constraint.h"



using namespace std;
using namespace Util;

namespace base {
namespace sheetmusic {
	
	/// where T : effect
	/// 
	template <class T>
	class sm_t : T_constraint_t<T, effect_t>
	{

		sm_info_t* sm_info;
		
		ctrl_point_info_t* ctrl_point_info;
		
		sm_metadata_t* sm_metadata;
		
		vector<event_t*>* events;

	public:
		
		sm_t(sm_t* sm = NULL);

		int set_events(vector<event_t*>* e);

		vector<event_t*>* get_events();

	protected:

	};


}}



#endif