#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"



using namespace std;
using namespace Util;

namespace Base {
namespace sheetmusic {
	
	/// where T : effect
	/// 
	template <class T>
	class sm_t : TConstraint<T, Effect>
	{

		sm_info_t* sm_info;
		
		ctrl_point_info_t* ctrl_point_info;
		
		sm_metadata_t* sm_metadata;
		
		vector<Event*>* events;

	public:
		
		sm_t(sm_t* sm = NULL);

		int set_events(vector<Event*>* e);

		vector<Event*>* get_events();

	protected:

	};


}}



#endif