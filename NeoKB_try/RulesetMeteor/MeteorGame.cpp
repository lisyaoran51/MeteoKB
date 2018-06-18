#include"MeteorGame.h"
#include "Config\MeteorConfigManager.h"

using namespace Meteor;
using namespace Util::Hierachal;
using namespace Meteor::Config;


int MeteorGame::load()
{

	if (!GetCache<FrameworkConfigManager>("FrameworkConfigManager")) {
		FrameworkConfigManager* fConfigManager = new FrameworkConfigManager();
		fConfigManager->Set(FrameworkSetting::PatternGenerator, "MeteorPatternGenerator");
		// TODO: ³]©w....
		Cache<FrameworkConfigManager>(fConfigManager);
	}

	

	

	return 0;
}

MeteorGame::MeteorGame(): RegisterType("MeteorGame")
{
}
