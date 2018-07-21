#include "Program.h"

#include "Base/Play/Session.h"
#include "Util/ProgramInitializer.h"

using namespace Base;
using namespace Meteor;
using namespace Base::Play;
using namespace Util;
using namespace Util::Hierachal;



int main(int argc, char *argv[]) {

	LOG(LogLevel::Info) << "int main(int,char*) : Program start.";

	// 建立instance creator和sm decoder
	ProgramInitializer::Initialize();

	LOG(LogLevel::Info) << "int main(int,char*) : Create game [MeteorGame].";
	Game* game = new MeteorGame();

	LOG(LogLevel::Fine) << "int main(int,char*) : Create Config Manager [FrameworkConfigManager].";
	FrameworkConfigManager* fConfigManager = new FrameworkConfigManager();
	fConfigManager->Async();
	fConfigManager->Set(FrameworkSetting::PatternGenerator, string("MeteorPatternGenerator"));
	fConfigManager->Set(FrameworkSetting::HardwareVersion, 10);
	fConfigManager->Set(FrameworkSetting::Width, 3); //要改
	fConfigManager->Set(FrameworkSetting::Height, 24);
	fConfigManager->Set(FrameworkSetting::BlackKeyHeight, 16);
	fConfigManager->Set(FrameworkSetting::TargetHeight, 20);
	fConfigManager->Set(FrameworkSetting::BlackKeyTargetHeight, 14);
	fConfigManager->Set(FrameworkSetting::StartPitch, 48);
	fConfigManager->Set(FrameworkSetting::FrameRate, 10);
	// TODO: 設定....
	game->Cache<FrameworkConfigManager>(fConfigManager);

	LOG(LogLevel::Fine) << "int main(int,char*) : Create Config Manager [MeteorConfigManager].";
	MeteorConfigManager* mConfigManager = new MeteorConfigManager();
	mConfigManager->Async();
	game->Cache<MeteorConfigManager>(mConfigManager);

	// 1. cache session
	// TODO: 之後把session改成我要的

	LOG(LogLevel::Info) << "int main(int,char*) : Create Sm Manager.";
	SmManager* smManager = new SmManager();

	LOG(LogLevel::Info) << "int main(int,char*) : Importing Sheetmusics.";
	smManager->Import(new vector<string>{ "Resources/Sms" });

	LOG(LogLevel::Info) << "int main(int,char*) : Create Session with Meteor ruleset and Sm manager.";
	Session* session = new Session(new RulesetInfo("MeteorRuleset"), smManager);

	game->Cache<Session>(session);

	game->Async();

	LOG(LogLevel::Info) << "int main(int,char*) : Run the game.";
	game->Run();


	return 0;
}
