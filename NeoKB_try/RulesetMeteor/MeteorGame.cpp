#include"MeteorGame.h"

using namespace Meteor;

int MeteorGame::load()
{
	Cache<MeteorConfigManager>(new MeteorConfigManager());

	// ����q
	// Cache �����M�W�h���
	// TODO:....


	player = new Player();

	AddChild(Player);

	return 0;
}
