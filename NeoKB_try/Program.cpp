#include "Program.h"
#include "Base\Play\Session.h"

using namespace Base;
using namespace Meteor;
using namespace Base::Play;



int main() {

	Game* game = new MeteorGame();

	// 1. cache session
	// TODO: 之後把session改成我要的
	game->Cache<Session>(new Session());


	game->Async();


	game->Run();


	return 0;
}
