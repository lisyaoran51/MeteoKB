#ifndef GAME_H
#define GAME_H

#include "../Util/Hierachal/ChildAddable.h"
#include "Play\Player.h"
#include "../Util/Update/Updater.h"

using namespace Util::Hierachal;
using namespace Base::Play;
using namespace Util::Update;


namespace Base {



	class Game: public ChildAddable {

		/// <summary>
		/// �o����ӹC��
		/// </summary>
		int load();

		// TODO: ��{����g��thread

		// update thread

		// draw thread

		// audio thread

		// input thread

		Updater* updater;

	public:

		Game();

		int Run();

	protected:

		Player* player;

	};

}




#endif