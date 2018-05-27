#ifndef SHEETMUSIC_INFO_H
#define SHEETMUSIC_INFO_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "sheetmusic_metadata.h"
#include "sheetmusic_difficulty.h"
#include "../ruleset/ruleset.h"



using namespace std;
using namespace Util;
using namespace Base::ruleset;

namespace Base {
namespace sheetmusic {
	
	 
	class sm_info_t
	{

	public:

		int id;

		int sm_version;

		sm_metadata_t* metadata;

		sm_difficulty_t* difficuty;

		string path;

		int ruleset_id;

		int version;

		ruleset_t* ruleset;

		ruleset_info_t* ruleset_info;



	};


}}



#endif