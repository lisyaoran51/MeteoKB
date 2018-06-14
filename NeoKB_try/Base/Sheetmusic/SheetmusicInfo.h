#ifndef SHEETMUSIC_INFO_H
#define SHEETMUSIC_INFO_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "SheetmusicMetadata.h"
#include "SheetmusicDifficulty.h"
#include "../Ruleset/Ruleset.h"
#include "SheetmusicSetInfo.h"



using namespace std;
using namespace Util;
using namespace Base::Rulesets;

namespace Base {
namespace Sheetmusics {
	
	 
	struct SmInfo
	{

		int id;

		int smVersion;

		SmMetadata* metadata;

		SmDifficulty* difficuty;

		string path;

		int rulesetId;

		int version;

		Ruleset* ruleset;

		RulesetInfo* rulesetInfo;

		SmSetInfo* smSetInfo;

	};


}}



#endif