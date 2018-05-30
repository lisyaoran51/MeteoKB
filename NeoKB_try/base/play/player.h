#ifndef PLAYER_H
#define PLAYER_H

#include "../../Util/Update/Updatable.h"
#include "../../Util/Hierachal/ChildAddable.h"
#include"../Ruleset/RulesetExecutor.h"



using namespace Util::Hierachal;
using namespace Base::Ruleset;

namespace Base {
namespace Play {

	class Player: ChildAddable {

		SmManager* smManager;

		WorkingSm* workingSm;

		RulesetInfo* rulesetInfo;

		RulesetExecutor<Event>* rulesetExecutor;

		Playfield* playfield;

		/// <summary>
		/// load in things like sm, Ruleset info. then create Ruleset executor
		/// </summary>
		int load();

	public:

		Player();

		~Player();

	};

}
}








#endif