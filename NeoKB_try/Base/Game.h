#ifndef GAME_H
#define GAME_H

#include"../Util/Hierachal/ChildAddable.h"

using namespace Util::Hierachal;

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