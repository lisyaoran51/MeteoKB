#ifndef SESSION_H
#define SESSION_H

#include "../../Util/Hierachal/ChildAddable.h"
#include "../Ruleset/RulesetInfo.h"
#include "../Sheetmusic/WorkingSheetmusic.h"
#include "../Sheetmusic/SheetmusicManager.h"

using namespace Util::Hierachal;
using namespace Base::Sheetmusics;


namespace Base {
namespace Play {

	class Session : public ChildAddable {

		int load();

		int load(RulesetInfo* r, SmManager* s);

	public:

		Session();

		RulesetInfo* GetRulesetInfo();

		WorkingSm* GetWorkingSm();

	protected:

		RulesetInfo* rulesetInfo;

		SmManager* smManager;

		SmInfo* smInfo;

	};

}}





#endif