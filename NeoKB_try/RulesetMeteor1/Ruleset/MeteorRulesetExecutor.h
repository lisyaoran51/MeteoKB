#ifndef METEOR_RULESET_EXCUTOR_H
#define METEOR_RULESET_EXCUTOR_H

#include "../../Base/Ruleset/Ruleset.h"


using namespace Base::Rulesets;
using namespace Base::Schedulers::Events;

namespace Meteor {
namespace Rulesets {

	class MeteorRulesetExecutor: public RulesetExecutor<Event>{

		///<summary>
		/// �o�Ӹհ�����Ϊ�
		/// �bget event processor�ɡA��o��event�n�Ψ쪺effect mapper�\�i�h???
		/// **�γo�Ӥ��Ӧn�A�į�|�ܮt�A���Ӫ����ΧP�_���A���n�dtable
		/// **�dtable���n�B�O�i�H��executor�Mevent processor���}�A���C���X
		///</summary>
		map<string, string> eventProcessorTable;

		virtual SmConverter* createSmConverter(PatternGenerator* pg);

		virtual SmPostprocessor* createSmPostprocessor();

		int load();

	public:

		MeteorRulesetExecutor();

	protected:

		Playfield* createPlayfield();

		virtual EventProcessor<Event>* getEventProcessor(Event* e);

		string GetProcessorType(string eventType);

	};

}
}







#endif