#include "Program.h"
#include "Base\Play\Session.h"

using namespace Base;
using namespace Meteor;
using namespace Base::Play;



int main() {

	Game* game = new MeteorGame();

	// 1. cache session
	// TODO: �����session�令�ڭn��
	game->Cache<Session>(new Session());


	game->Async();


	game->Run();


	return 0;
}
