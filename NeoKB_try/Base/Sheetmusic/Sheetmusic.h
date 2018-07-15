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
		
		Sm(Sm<T>* sm = NULL) {
			if (sm) {
				// TODO: 應該是要附置一份，而不是直接指過去
				SetSmInfo(sm->GetSmInfo());
				SetSmMetadata(sm->GetSmMetadata());
				SetEvents(sm->GetEvents());
				SetRulesetInfo(sm->GetRulesetInfo());
			}
			else {
				SetSmInfo(new SmInfo());
				SetSmMetadata(new SmMetadata());
				SetEvents(new vector<T*>());
				// SetRulesetInfo
			}
		}

		~Sm() {
			delete smInfo;
			delete smMetadata;
			delete events;
			delete rulesetInfo;
		}

		int SetSmInfo(SmInfo* si) {
			smInfo = si;
			return 0;
		}

		SmInfo* GetSmInfo() {
			return smInfo;
		}

		int SetSmMetadata(SmMetadata* sm) {
			smMetadata = sm;
			return 0;
		}

		SmMetadata* GetSmMetadata() {
			return smMetadata;
		}

		int SetEvents(vector<T*>* e) {
			events = e;
			// TODO: sort
			sort(e->begin(), e->end());
			return 0;
		}

		vector<T*>* GetEvents() {
			return events;
		}

		int SetRulesetInfo(RulesetInfo* r) {
			rulesetInfo = r;
			return 0;
		}

		RulesetInfo* GetRulesetInfo() {
			return rulesetInfo;
		}

	};


}}



#endif