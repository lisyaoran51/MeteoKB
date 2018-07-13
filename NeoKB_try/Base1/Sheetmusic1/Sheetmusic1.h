#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "SheetmusicInfo.h"
#include "SheetmusicMetadata.h"
#include "../Ruleset/RulesetInfo.h"
#include "../Scheduler/Event/Event.h"



using namespace std;
using namespace Util;
using namespace Base::Rulesets;
using namespace Base::Schedulers::Events;


namespace Base {
namespace Sheetmusics {
	
	/// where T : effect
	/// 
	template <typename T>
	class Sm : TConstraint<T, Event>
	{

		SmInfo* smInfo;
		
		SmMetadata* smMetadata;
		
		vector<T*>* events;

		RulesetInfo* rulesetInfo;

	public:
		
		Sm(Sm<T>* sm = NULL);

		~Sm();

		int SetSmInfo(SmInfo* si);

		SmInfo* GetSmInfo();

		int SetSmMetadata(SmMetadata* sm);

		SmMetadata* GetSmMetadata();

		int SetEvents(vector<T*>* e);

		vector<T*>* GetEvents();

		int SetRulesetInfo(RulesetInfo* r);

		RulesetInfo* GetRulesetInfo();

	};


}}



#endif