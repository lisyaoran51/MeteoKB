#include "Program.h"

#include "Base/Play/Session.h"
#include "Util/ProgramInitializer.h"

using namespace Base;
using namespace Meteor;
using namespace Base::Play;
using namespace Util;
using namespace Util::Hierachal;



int main(int argc, char *argv[]) {

	// 建立instance creator和sm decoder
	ProgramInitializer::Initialize();


	Game* game = new MeteorGame();

	FrameworkConfigManager* fConfigManager = new FrameworkConfigManager();
	fConfigManager->Set(FrameworkSetting::PatternGenerator, "MeteorPatternGenerator");
	fConfigManager->Set(FrameworkSetting::HardwareVersion, 10);
	fConfigManager->Set(FrameworkSetting::Width, 12); //要改
	fConfigManager->Set(FrameworkSetting::Height, 24);
	fConfigManager->Set(FrameworkSetting::BlackKeyHeight, 16);
	fConfigManager->Set(FrameworkSetting::TargetHeight, 20);
	fConfigManager->Set(FrameworkSetting::BlackKeyTargetHeight, 14);
	fConfigManager->Set(FrameworkSetting::StartPitch, 48);
	// TODO: 設定....
	game->Cache<FrameworkConfigManager>(fConfigManager);


	// 1. cache session
	// TODO: 之後把session改成我要的

	Session* session = new Session();

	SmManager* smManager = new SmManager();

	smManager->Import(new vector<string>{"Resources/Sms"});

	session->Cache(new RulesetInfo("Meteor"));

	session->Cache<SmManager>(smManager);

	session->Async();

	game->Cache<Session>(session);


	game->Async();


	game->Run();


	return 0;
}
