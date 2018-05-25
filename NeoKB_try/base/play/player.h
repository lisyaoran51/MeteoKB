#ifndef PLAYER_H
#define PLAYER_H

#include "../../Util/Hierachal/updatable.h"

using namespace Util::Hierachal;


namespace base {
namespace play {

	class player_t: Updatable {

		ruleset_info_t* ruleset_info;

		ruleset_executor_t* ruleset_executor;

		Playfield* playfield;

		/// <summary>
		/// load in things like sm, ruleset info. then create ruleset executor
		/// </summary>
		int privateLoad(int argc, char** argv);




	};

}
}








#endif