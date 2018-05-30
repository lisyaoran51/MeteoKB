#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Sheetmusic {
	
	/// where T : effect
	/// 
	template <class T>
	class Sm : TConstraint<T, Effect>
	{

		sm_info_t* sm_info;
		
		ctrl_point_info_t* ctrl_point_info;
		
		sm_metadata_t* sm_metadata;
		
		vector<Event*>* events;

	public:
		
		Sm(Sm* sm = NULL);

		int set_events(vector<Event*>* e);

		vector<Event*>* get_events();

	protected:

	};


}}



#endif