#include"MeteorGame.h"

using namespace Meteor;

int MeteorGame::load()
{
	Cache<MeteorConfigManager>(new MeteorConfigManager());

	// 先選歌
	// Cache 哥曲和規則資料
	// TODO:....


	player = new Player();

	AddChild(Player);

	return 0;
}
