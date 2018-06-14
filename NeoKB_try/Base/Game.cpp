#include"Game.h"
#include"Config\FrameworkConfigManager.h"
#include"../Util/Update/Updater.h"

using namespace Base;
using namespace Base::Config;
using namespace Util::Update;
using namespace Util::Hierachal;

int Game::load()
{
	Cache<FrameworkConfigManager>(new FrameworkConfigManager());
	Cache<Updater>(updater = new Updater());

	return 0;
}

Game::Game(): RegisterType("Game")
{
	registerLoad(bind(&Game::load,this));
}

int Base::Game::Run()
{
	bool running = true;
	while (running) {
		updater->Update();
	}

	return 0;
}
