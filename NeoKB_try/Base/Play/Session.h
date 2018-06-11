#ifndef SESSION_H
#define SESSION_H

#include "../../Util/Hierachal/ChildAddable.h"
#include "../Ruleset/RulesetInfo.h"
#include "../Sheetmusic/WorkingSheetmusic.h"

using namespace Util::Hierachal;


namespace Base {
namespace Play {

	class Session : public ChildAddable {

	public:

		RulesetInfo* GetRulesetInfo();

		WorkingSm* GetWorkingSm();

	};

}}





#endif